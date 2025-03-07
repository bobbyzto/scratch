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

#include <stddef.h>

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

#ifdef __cplusplus
    extern "C" {
#endif

// Code here

#ifdef __cplusplus
    }
#endif    

#endif // BASE_H
