/*
 * =====================================================================================
 *
 *       Filename:  gori.h
 *
 *    Description:  GoriGoriVM
 *
 *        Version:  1.0
 *        Created:  8/4/2016 4:02:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __GORIGORI_INST__
#define __GORIGORI_INST__

#include <stdio.h>
#include "data.h"

#define MAX_ADDR 2048

typedef struct gorigori_vm gori;

struct gorigori_vm {
    int max_addr;
    int used_addr;
    FILE* stdi; // *STANDARD-INPUT*
    FILE* stdo; // *STANDARD-OUTPUT*
    FILE* stde; // *STANDARD-ERROR*

    frame* vm;
};

gori* new_gorigori_vm();

#endif
