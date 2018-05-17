//
// Created by Maciej on 06.05.2018.
//

#ifndef BIGLICZBY_BIGNUMBERS_H
#define BIGLICZBY_BIGNUMBERS_H

#include <iostream>
#include <string>
#include <cstring>

class BigNumbers{
public:
    BigNumbers();

    BigNumbers(const char* number);

    BigNumbers(const BigNumbers &o1);

    ~BigNumbers();

    BigNumbers &operator = (const BigNumbers &o1);

    BigNumbers operator + (const BigNumbers &o1)const;

    friend std::istream &operator >> (std::istream &s1, BigNumbers &o1);

    friend std::ostream &operator << (std::ostream &s1, BigNumbers &o1);

    friend void Reverse(std::string , BigNumbers&);
private:
    std::string str;
};
#endif //BIGLICZBY_BIGNUMBERS_H
