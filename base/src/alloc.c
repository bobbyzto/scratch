#include "base.h"

struct arena 
{
    char * beg;
    char * end;
};

void * memset(void * destination, i32 val, usize count)
{
  char * bytes = (char *)destination;
  while ( count-- )
    *bytes++ = (char)value;
  return destination;
}

void * alloc(arena * a, size size, size align, size count)
{
  size padding = -(uptr)a->beg & (align - 1);
  size available = a->end - a->beg - padding;
  if ( available < 0 || count > available/size )
  {
    abort(); // out-of-memory policy
  }
  
  void * p = a->beg + padding;
  a->beg += padding + count * size;
  return memset(p, 0, count * size);
}

