/*
 * =====================================================================================
 *
 *       Filename:  type.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2016 09:26:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z.Shang (), shangzhanlin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __gori_type_h__
#define __gori_type_h__

#include <stdbool.h>

typedef struct gori_type gori_t;
typedef struct gori_value gori_v;
typedef gori_v *(* marble_phantasm)(void*);
typedef enum {

} prim_t;

struct gori_type{
    bool is_prim;
    union {
        struct {
            prim_t type;
        } prim;
        struct {
            char* type;
        } defn;
    } is;
};

struct gori_value{
    gori_t* type;
    union {
        struct {

        } prim_v;
        struct {
            marble_phantasm get;
            //Function that turns a void pointer into valid gorigori value
            void* v;
        } defn_v;
    } is;
};

#endif
