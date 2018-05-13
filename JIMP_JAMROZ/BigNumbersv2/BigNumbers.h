//
// Created by Maciej on 11.05.2018.
//

#ifndef BIGNUMBERSV2_BIGNUMBERS_H
#define BIGNUMBERSV2_BIGNUMBERS_H
#include <iostream>
#include <cstring>
#include <algorithm>

class BigNumbers {
public:
    BigNumbers();

    explicit BigNumbers(const char*);

    BigNumbers(const BigNumbers &o1);

    ~BigNumbers();

    BigNumbers &operator = (const BigNumbers &o1);

    BigNumbers operator + (const BigNumbers &o1)const;

    friend std::ostream &operator << (std::ostream &s1,const BigNumbers &o1);

    friend std::istream &operator >> (std::istream &s1, BigNumbers &o1);
protected:
    char *number_;
};

class BigNumbersExtended : public BigNumbers{
public:
    BigNumbersExtended() : BigNumbers(){};

    explicit BigNumbersExtended(const char* number) : BigNumbers(number){};

    BigNumbersExtended(const BigNumbers &o1) : BigNumbers(o1){};

    bool operator == (const BigNumbersExtended &o1) const;

    bool operator != (const BigNumbersExtended &o1)const;

    BigNumbersExtended operator * (const BigNumbersExtended&o1)const;

    bool operator > (const BigNumbersExtended &o1)const;

    bool operator < (const BigNumbersExtended &o1)const;
};

#endif //BIGNUMBERSV2_BIGNUMBERS_H
