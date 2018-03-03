//
// Created by maciej on 03.03.18.
//

#include "factorial.h"

int factorial ( int n){
    if (n==0) return 1;
    int i, res = 1;
    for (i = 1; i<=n; i++)
        res *= i;
    return res;
}

int factorial_reku (int n){
    if (n==0) return 1;
    else return n*factorial_reku(n-1);
}