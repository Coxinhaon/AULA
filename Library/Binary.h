#include <stdio.h>
#ifndef BINARY_H
#define BINARY_H
    int And(int a,int b){
        return a&b;
    }
    int Or(int a,int b){
        return a|b;
    }
    int Not(int a){
        return ~a;
    }
    int Xor(int a,int b){
        return a^b;
    }
    int ShiftRight(int a,int b){
        return a>>b;
    }
    int ShiftLeft(int a,int b){
        return a<<b;
    }
    int Nand(int a,int b){
        return ~(a&b);
    }
    int Nor(int a,int b){
        return ~(a|b);
    }
    int Nxor(int a,int b){
        return ~(a^b);
    }

#endif
