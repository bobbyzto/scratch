/***************************************************************
* 
* Utility code incl. 
*   - Helper macros
*   - Atomic type aliases
*   - Misc. general purpose code
*
* NOTE:
*
* (!)   Code written here should conform to ANSI C or C99
*   standard at the latest. See 'Engineering problem solving 
*   with ANSI C' by Delores M. Etter', and 'Modern C 
*   Programming' by Orhan Gazi for reference.
*
*
***************************************************************/

#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

#include <stdint.h>
#include <stddef.h>
#include <uchar.h>

// Atomics
typedef uint8_t     u8;
typedef char16_t   c16;
typedef int32_t    b32;
typedef int32_t    i32;
typedef uint32_t   u32;
typedef uint64_t   u64;
typedef float      f32;
typedef double     f64;
typedef uintptr_t uptr;
typedef char      byte;
typedef ptrdiff_t size;
typedef size_t   usize;

// Macros
#define countof(a) (size)(sizeof(a) / sizeof(*(a)))
#define lengthof(s) countof(s)-1
// #define new(a,t,n) (t*)alloc(a, sizeof(t), _Alignof(t),n)
#define container_of(ptr, type, member) \
    ((type *)(char *)(ptr) - offsetof(type, member))

#ifdef __cplusplus
    extern "C" {
#endif

// Arena allocator
typedef struct arena arena;
void * memset(void *, int, usize);
void * alloc(arena *, size, size, size);

// Strings
typedef struct s8 s8;
#define S(s) (s8){(u8*)s, countof(s)-1}
struct s8 {
  u8    * data;
  size     len;
};

/* String methods */
extern s8   s8span(u8 *, u8 *);
extern b32  s8equals(s8, s8);
extern size s8compare(s8, s8);
extern u64  s8hash(s8);
extern s8   s8trim(s8);
extern s8   s8copy(u8 *, u8 *);
/*extern s8   s8clone(s8);*/


// Code here

#ifdef __cplusplus
    }
#endif    

#endif // BASE_H
