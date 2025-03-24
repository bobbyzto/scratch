#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "test.h"

/* C Version of Logger (belongs in logger.h) */
#define LOG_MSG(fmt, ...) \
  fprintf(stdout, fmt, ##__VA_ARGS__)

/* Generic definitions */
const i32 noHistory = -1;
const i32 noParent = -1;

typedef i32 state;
typedef i32 msgPort;
typedef i32 msgSignal;

typedef struct stateCB 
{
  state parent;
  state history;
} stateCB;

typedef struct msgHeader
{
  msgSignal signal;
  msgPort     port;
} msgHeader;

msgHeader * msg;

enum { top, B, B1 };        // symbolic names for states
#define numStates 3         // total no. of states in FSM

/* FSM-specific definitions */
typedef struct fsmCB
{
  state curState;
  i32      numSt;
  stateCB * states[numStates];
  i32 v1;
  i32 v2;
} fsmCB;

fsmCB * fsm;
/* input signal values (belongs in prototype class) */ 
enum { init, sig1, sig2 };
/* port values (belongs in structure part of actor spec) */
enum fsmPorts { sysPort, port1 };

/* transition chain values  */
enum { noTrigger, t1chain, t2chain, t4chain };

/* Generic utility functions */
void nextState(state st);
state currentState();
state parentOf(state st);
state historyOf(state st);
void setHistory(state st, state histSt);

void unhandledMsg();
fsmCB * createFSM();
void releaseVars(fsmCB * fsmPtr);
void initVars(fsmCB * fsmPtr);

/* State-specific procedures */
void enterB1();
void exitB1();
i32 B1trigs();
void enterB();
void exitB();
i32 Btrigs();
void t1();
void t2();
void t3();
void t4();
i32 topTrigs();

extern void transitionChains(i32);
extern void enterHistory(state);
void doInitTransFor(state st);
void doHistoryFor(state st);
void doExitFrom(state st);
void transitionChains(i32 triggerIndex);
i32 getTriggers(state st);

/* Generic routines which must be PRIVATE to each FSM */ 

void executeExits(state st);
void resetFSM(fsmCB * fsmPtr);
void processMsg(fsmCB * fsmPtr, msgHeader * aMsgPtr);
void startFSM(fsmCB * fmsPtr, msgHeader * initMsg);
void terminateFSM(fsmCB * fsmPtr);

i32 main(void)
{
  // create FSM
  fsmCB * fsmPtr = createFSM();

  // allocate msg block and start FSM
  msgHeader * aMsgPtr = malloc(sizeof(msgHeader));
  aMsgPtr->signal = init;
  aMsgPtr->port   = sysPort;
  startFSM(fsmPtr, aMsgPtr);

  // create a <sig1,port1> message and process it:
  aMsgPtr->signal = sig1;
  aMsgPtr->port  = port1;
  processMsg(fsmPtr, aMsgPtr);

  // create a <sig2,port1> message and process it:
  aMsgPtr->signal = sig2;
  processMsg(fsmPtr, aMsgPtr);

  // create an invalid message and process it:
  aMsgPtr->signal = 3;
  processMsg(fsmPtr, aMsgPtr);

  terminateFSM(fsmPtr);
  free(aMsgPtr);

  return 0;
}

/* Generic utility functions */
void nextState(state st)
{
  fsm->curState = st;
}
state currentState()
{
  return fsm->curState;
}
state parentOf(state st)
{
  return (fsm->states[st])->parent;
}
state historyOf(state st)
{
  return (fsm->states[st])->history;
}
void setHistory(state st, state histSt)
{
  (fsm->states[st])->history = histSt;
}

void unhandledMsg()
{
  LOG_MSG("Message unhandled: %i\n", msg->signal); 
}

fsmCB * createFSM()
{
  fsmCB * cbPtr = malloc(sizeof(fsmCB));
  cbPtr->numSt = numStates;

  // allocate state cbs:
  for (i32 i=0 ; i<numStates ; ++i)
  {
    cbPtr->states[i] = malloc(sizeof(stateCB));
  }
  // link each state to its parent state:
  (cbPtr->states[top])->parent = noParent;
  (cbPtr->states[B])->parent = top;
  (cbPtr->states[B1])->parent = B;

  return cbPtr;
}

void releaseVars(fsmCB * fsmPtr)
{
}

void initVars(fsmCB * fsmPtr)
{
  releaseVars(fsmPtr);
  fsmPtr->v1 = 0;
  fsmPtr->v2 = 0;
}

/* State-specific procedures */
void enterB1()
{ 
  LOG_MSG("entered B1\n");
}

void exitB1()
{
  LOG_MSG("exited B1\n");
}

void t4()
{
  LOG_MSG("transition <t4:B> executed\n");
}

i32 B1trigs()
{
  switch(msg->port)
  {
    case port1:
      switch(msg->signal)
      {
        case sig2:
          if (fsm->v2 == 0)
            return t4chain;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };
  return noTrigger;
}

void enterB()
{
  LOG_MSG("entered B\n");
}

void exitB()
{
  LOG_MSG("exited B\n");
}

i32 Btrigs()
{
  switch(msg->port)
  {
    case port1:
      switch(msg->signal)
      {
        case sig1:
          return t2chain;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };
  return noTrigger; 
}

void t1()
{
  LOG_MSG("transition <t1:top> executed\n");
}

void t2()
{
  LOG_MSG("transition <t2:top> executed\n");
}

void t3()
{
  LOG_MSG("transition <t3:top> executed\n"); 
}

i32 topTrigs()
{
  switch(msg->port)
  {
    case sysPort:
      switch(msg->signal)
      {
        case init:
          return t1chain;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };
  return noTrigger; 
}

/*extern void transitionChains(i32);*/
/*extern void enterHistory(state);*/

void doInitTransFor(state st)
{
  switch(st)
  {
    case top:
      transitionChains;
      break;
    default:
      break;
  };
}
void doHistoryFor(state st)
{
  state hist = historyOf(st);
  switch(st)
  {
    case top: if (hist == B)
    {
        enterB();
        enterHistory(st);
        return;
    } 
      break;
    case B: if (hist == B1)
    {
        enterB1();
        return;
    }
      break;
  };
}

void doExitFrom(state st)
{
  switch(st)
  {
    case top:   return;
    case B:     exitB();
                return;
    case B1:    exitB1();
                return;
    default:    break;
  };
}

void transitionChains(i32 triggerIndex)
{
  switch(triggerIndex)
  {
    case t1chain:   t1();
                    enterB();
                    t3();
                    enterB1();
                    nextState(B1);
                    break;
    case t2chain:   t2();
                    enterB();
                    enterHistory(B);
                    break;
    case t4chain:   t4();
                    enterB1();
                    nextState(B1);
                    break;
    default:        break;
  };
}

i32 getTriggers(state st)
{
  switch(st)
  {
    case top: return topTrigs();
    case B:   return Btrigs();
    case B1:  return B1trigs();
    default:  break;
  };
  return noTrigger;
}

/* Generic routines which must be PRIVATE to each FSM */ 
void enterHistory(state st)
{
  if (historyOf(st) == noHistory)
    doInitTransFor(st);
  else
    doHistoryFor(st);
}

void executeExits(state st)
{
  state nxtSt = currentState();
  while (nxtSt)
  {
    doExitFrom(nxtSt);
    state prev = nxtSt;
    nxtSt = parentOf(prev);
    if (nxtSt != noParent)
      setHistory(nxtSt, prev);
  };
}
void resetFSM(fsmCB * fsmPtr)
{
  initVars(fsmPtr);
  for(i32 i=0 ; i<(fsmPtr->numSt) ; ++i)
  {
    (fsmPtr->states[i])->history = noHistory;
  }
  fsmPtr->curState = top;
}
void processMsg(fsmCB * fsmPtr, msgHeader * aMsgPtr)
{
  fsm = fsmPtr;
  msg = aMsgPtr;
  state st = currentState();
  i32 trigger = noTrigger;

  // search for a state that corresponds to current msg:
  while(st >= top)
  {
    trigger = getTriggers(st);
    if (trigger > noTrigger)
    {
      executeExits(st);
      transitionChains(trigger);
      return;   // event handled successfully
    } else 
    {
      st = parentOf(st);
    }
  };
  // if reached, no state responded to the msg:
  unhandledMsg();
}

void startFSM(fsmCB * fsmPtr, msgHeader * initMsg)
{
  resetFSM(fsmPtr);
  // configure and process initial message:
  initMsg->signal = init;
  initMsg->port   = sysPort;
  processMsg(fsmPtr, initMsg);
}

void terminateFSM(fsmCB * fsmPtr)
{
  releaseVars(fsmPtr);
  for (i32 i=0 ; i<fsmPtr->numSt ; ++i)
    free(fsmPtr->states[i]);
  free(fsmPtr);
  fsmPtr = NULL;
}


