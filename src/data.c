/*
 * =====================================================================================
 *
 *       Filename:  data.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2016 09:02:44 PM
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
#include "gc.h"

void env_init(){
    toplevel_env = (env *)malloc(sizeof(env));
    toplevel_env->next = NULL;
    toplevel_env->entry = NULL;
}

void add_to_top_level(stv_triple * stv){
    env * e = new_env();
    e->next = toplevel_env;
    e->entry = stv;
    toplevel_env = e;
}

env* new_env(){
    env* e = (env *)malloc(sizeof(env));
    e->next = NULL;
    e->entry = NULL;
    return e;
}

frame* empty_frame(){
    frame* f = (frame *)gc_malloc(sizeof(frame));
    f->s = NULL;
    f->e = NULL;
    f->c = NULL;
    f->d = NULL;
    f->next = NULL;
    return f;
}

