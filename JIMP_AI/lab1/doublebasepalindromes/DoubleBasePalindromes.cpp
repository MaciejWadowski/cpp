//
// Created by maciej on 03.03.18.
//
#include <iostream>
#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int n){
    int i;
    for (i = 11 ; i <= n; i += 2){
        if (IsDecimalPalindrome(i))
            if (IsBinaryPalindrome(i))
                std::cout << i << " ";
    }
}

bool IsDecimalPalindrome(int value){
    int b = 0, i, j = value;
    while (value > 0){
        i = value%10;
        b  = b*10 + i;
        value /= 10;
    }
    if (b == j) return true;
    else return false;
}

bool IsBinaryPalindrome(int value){
    char binary[20], binary2[20];
    int size = 0;
    while (value > 0){
        if (value%2) binary[size] = '1' ;
        else binary[size] = '0';
        value /= 2;
        size++;
    }
    int k = size - 1, j;
    for (j = 0; j < size ; j++, k--)
        binary2[j] =  binary[k];
    for (j = 0; j < size; j++)
        if (binary2[j] != binary[j]) return false;
    return true;
}