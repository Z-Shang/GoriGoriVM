/*
 * =====================================================================================
 *
 *       Filename:  gc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2016 03:31:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

#include "gc.h"

void gc_init(){
    GC_HEAP = (gc_obj**)calloc(MAX_GC_OBJ, sizeof(gc_obj*));
    gc_count = 0;
}

void put_on_heap(gc_obj * o){
    int i = gc_count;
    while(GC_HEAP[i] != NULL){
        if(i >= MAX_GC_OBJ){
            i = 0;
        }else{
            i++;
        }
    }
    GC_HEAP[i] = o;
    o->pos = i;
    gc_count++;
}

void* gc_malloc(size_t size){
    if(gc_count >= MAX_GC_OBJ){
        fprintf(stderr, "GC Overflow!\n");
        exit(1);
    }else{
        printf("Allocating %d\n", size);
        gc_obj* o;
        o = (gc_obj *)malloc(sizeof(gc_obj));
        o->size = size;
        o->ptr = malloc(size);
        o->ref_count = 1;
        o->gen = 0;
        put_on_heap(o);
        return o->ptr;
    }
}

void gc_release(gc_obj * o){
    if(o->gen == 2){
        if(o->ref_count > 0){
            o->ref_count--;
        }
        return;
    }
    o->ref_count--;
    if(o->ref_count <= 0){
        if(o->gen == 2){
            o->ref_count = 0;
            printf("%d is ETERNAL\n", o->pos);
        }else{
            GC_HEAP[o->pos] = NULL;
            free(o->ptr);
            free(o);
            gc_count--;
        }
    }
}

void* gc_ref(gc_obj * o){
    o->ref_count++;
    return o->ptr;
}

void gc_upgrade(gc_obj * o){
    if(o->gen < 2){
        o->gen++;
    }else{
        o->gen = 2;
    }
}

void gc_sweep(unsigned char gen){
    unsigned int t = 0;
    unsigned int current_count = gc_count;
    printf("Sweeping %d items\n", current_count);
    for(int i = 0; i < MAX_GC_OBJ; i++){
        if(t >= current_count){
            break;
        }
        if(GC_HEAP[i] != NULL){
            t++;
            if(GC_HEAP[i]->gen <= gen){
                free(GC_HEAP[i]->ptr);
                free(GC_HEAP[i]);
                GC_HEAP[i] = NULL;
                gc_count--;
            }else{
                gc_upgrade(GC_HEAP[i]);
            }
        }
    }
    printf("Swept %d items\n", current_count - gc_count);
}

void print_gc_info(){
    printf("GC Count: %d\n", gc_count);
    unsigned int t = 0;
    for(int i = 0; i < MAX_GC_OBJ; i++){
        if(t >= gc_count){
            break;
        }
        if(GC_HEAP[i] != NULL){
            t++;
            printf("HEAP pos: %d size: %d checked", GC_HEAP[i]->pos, GC_HEAP[i]->size);
            switch(GC_HEAP[i]->gen){
                case 0:
                    printf("\tGen: YOUNG");
                    break;
                case 1:
                    printf("\tGen: OLD");
                    break;
                case 2:
                    printf("\tGen: ETERNAL");
                    break;
            }
            printf("\tRef Count: %d\n", GC_HEAP[i]->ref_count);
        }
    }
}
