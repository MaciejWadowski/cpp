//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

long long int factorial(int value) {
    long long int resu = 1;
    if ( value < 0 )
        for (int i = -1; i >= value; i--) resu = resu*i;
    else
        for ( int i = 1; i <= value; i++) resu = resu*i;
    return resu;
}
