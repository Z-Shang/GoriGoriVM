/*
 * =====================================================================================
 *
 *       Filename:  instructions.h
 *
 *    Description:  Instructions of GoriGoriVM
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

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

#define MAX_ADDR 2048

typedef enum GINST {
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
} GINST;

class GoriGoriVM {
    public:
        GoriGoriVM();

    private:
        int max_addr;
        int used_addr;
        istream* stdi;
        ostream* stdo;
};

#endif
