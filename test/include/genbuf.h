#ifndef GENBUF_H_INCLUDED
#define GENBUF_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

typedef struct DynamicArray
{
    size_t size;
    size_t used;
    void ** data;
};

#define da_at(da, i) (da)->data[(i)]
#define da_len(da)   (da)->used
/**/
/*bool da_init(*/
/*  DynamicArray * da, size_t init_size, size_t init_used)*/
/*{*/
/*  assert(init_size >= init_used);*/
/*  init_size = */
/*}*/

#endif // GENBUF_H_INCLUDED
