//
// Created by maciej on 03.03.18.
//

#include <iostream>
#include "Palindrome.h"

bool is_palindrome(std::string str){
    int size = str.size();
    std::string str2 = str;
    int i;
    for ( i = 0 ; i <= size; i++)
        str2[i] = str[size-i-1];
    if (str2 == str) return true;
    else return false;
}