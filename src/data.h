/*
 * =====================================================================================
 *
 *       Filename:  data.h
 *
 *    Description:  Basic Data Structures of GoriGori VM
 *
 *        Version:  1.0
 *        Created:  10/09/2016 02:30:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __containers_h__
#define __containers_h__

#include "type.h"

typedef struct stack stack;
typedef struct env env;
typedef struct control_path c_path;
typedef struct frame frame;
typedef struct symbol_type_pair st_pair;
typedef struct opt_type_pair ot_pair;
typedef struct symbol_type_value_triple stv_triple;
typedef struct gori_type gori_t;
typedef struct gori_value gori_v;
typedef struct type_env t_env;
typedef enum gori_opt {
    ADD,
    AP,
    CAR,
    CDR,
    CONS,
    DIV,
    DUM,
    EQ,
    G_NULL,
    GT,
    GTE,
    JOIN,
    LD,
    LDC,
    LDF,
    LT,
    LTE,
    MOD,
    MUL,
    NIL,
    RAP,
    READC,
    READI,
    RTN,
    SEL,
    STOP,
    SUB,
    WRITEC,
    WRITEI
} opt_t;

struct symbol_type_pair{
    char* symbol;
    gori_t* type;
};

struct opt_type_pair{
    opt_t opt;
    gori_t* type;
};

struct symbol_type_value_triple{
    char* symbol;
    gori_t* type;
    gori_v* value;
};

struct stack{
    st_pair* symlst;
    stack* next;
};

struct env{
    stv_triple* entry;
    env* next;
};

struct control_path{
    ot_pair* optlst;
    c_path* next;
};

struct frame{
    stack* s;
    env* e;
    c_path* c;
    frame* d;
    frame* next;
};

extern env* toplevel_env;
extern t_env* toplevel_types;

frame* empty_frame();

#endif
