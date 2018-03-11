//
// Created by maciej on 11.03.18.
//

#include "ReverseString.h"
#include <iostream>


std::string reverse(std::string str){
    using std::cout;
    const char *new_char = str.c_str();
    size_t size = str.size();
    if (new_char[0] == '\0') return "";
    std::string reverse_string = str.substr(1,size - 1 );
    return reverse(reverse_string) + str[0];
}