#include "../include/base.h"

/*#define S(s) (s8){(u8*)s, countof(s)-1}*/

s8 s8span(u8 * beg, u8 * end)
{
  s8 s = {};
  s.data = beg;
  s.len = end - beg;
  return s;
}

b32 s8equals(s8 a, s8 b)
{
  if ( a.len != b.len )
    return 0;

  for ( size i = 0; i < a.len; i++ )
  {
    if ( a.data[i] != b.data[i] )
      return 0;
  }
  return 1;
}

s8 s8copy(u8 * rs, u8 * cs)
{
  char * rc = rs;

  while ((*rs++ = *cs++))
  {
    // empty
  }
  return S(rc);
}
