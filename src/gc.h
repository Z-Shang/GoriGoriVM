/*
 * =====================================================================================
 *
 *       Filename:  gc.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2016 03:07:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __GORIGORI_GC_H_
#define __GORIGORI_GC_H_

#include <stdlib.h>

#define MAX_GC_OBJ 2048

typedef struct gorigori_gc_obj gc_obj;

struct gorigori_gc_obj{
    void* ptr;
    size_t size;
    unsigned int ref_count;
    unsigned char gen;

    unsigned int pos;
};

gc_obj** GC_HEAP;
unsigned int gc_count;

void gc_init();
void put_on_heap(gc_obj * o);
void* gc_malloc(size_t size);
void gc_release(gc_obj * o);
void* gc_ref(gc_obj * o);
void gc_upgrade(gc_obj * o);
void gc_sweep(unsigned char gen);

void print_gc_info();

#endif

