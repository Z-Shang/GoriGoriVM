/*
 * =====================================================================================
 *
 *       Filename:  gori.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2016 02:43:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#include "data.h"
#include "gori.h"
#include "gc.h"

gori* new_gorigori_vm(){
    gori* g = (gori *)gc_malloc(sizeof(gori));
    g->max_addr = MAX_ADDR;
    g->used_addr = 0;
    g->stdi = stdin;
    g->stdo = stdout;
    g->stde = stderr;
    g->vm = empty_frame();
    return g;
}
