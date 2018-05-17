//
// Created by Maciej on 11.05.2018.
//

#include "BigNumbers.h"

BigNumbers::BigNumbers() {
    number_ = nullptr;
}

BigNumbers::BigNumbers(const char *number) {
    if(number) {
        number_ = new char[strlen(number)];
        strcpy(number_, number);
    }

    else
        number_ = nullptr;
}

BigNumbers::BigNumbers(const BigNumbers &o1) {
    if(!o1.number_)
        number_ = nullptr;

    else{
        number_ = new char[strlen(o1.number_)];
        strcpy(number_,o1.number_);
    }
}

BigNumbers &BigNumbers::operator=(const BigNumbers &o1) {
    if(&o1 == this)
        return *this;

    else if(!o1.number_ && !number_){
        number_ = nullptr;
        return *this;
    }

    else if(!o1.number_ && number_){
        delete [] number_;
        number_ = nullptr;
        return *this;
    }

    else{
        if(number_)
            delete [] number_;
        number_ = new char[strlen(o1.number_)];
        strcpy(number_,o1.number_);
        return *this;
    }
}

BigNumbers::~BigNumbers() {
    if(number_) {
        delete[] number_;
        number_ = nullptr;
    }
}

std::ostream &operator<<(std::ostream &s1, const BigNumbers &o1) {
    if(o1.number_)
        s1 << o1.number_;
    return s1;
}

std::istream &operator>>(std::istream &s1, BigNumbers &o1) {
    if(o1.number_)
        delete [] o1.number_;

    std::string input;
    s1 >> input;
    o1.number_ = new char[input.size()+1];

    for(int i = 0; i < input.size(); i++)
        o1.number_[i] = input[i];

    o1.number_[input.size()] = '\0';
    return s1;
}

BigNumbers BigNumbers::operator+(const BigNumbers &o1) const {
    if(!o1.number_ && !number_)
        return BigNumbers();

    if(!o1.number_ )
        return BigNumbers(*this);

    if(!number_)
        return BigNumbers(o1);

    int size = (strlen(number_) >= strlen(o1.number_)) ? strlen(number_) : strlen(o1.number_);

    BigNumbers output;
    char result_number[size+1];
    int toAdd = 0, tmp = 0;
    int i = strlen(number_) - 1 , j = strlen(o1.number_) - 1, k = 0;

    while( i >= 0 && j >= 0){
        tmp = number_[i] - '0' + o1.number_[j] -'0';

        if(tmp + toAdd > 9){
            result_number[k] = char(tmp + toAdd - 10 + '0');
            toAdd = 1;
        }

        else{
            result_number[k] = char(tmp + toAdd + '0');
            toAdd = 0;
        }
        k++;
        i--;
        j--;
    }

    if( i > j ){
        while (i >= 0) {
            tmp = number_[i] + toAdd - '0';
            if (tmp > 9)
                result_number[k] = '0';
            else {
                result_number[k] = char(tmp + '0');
                toAdd = 0;
            }
            k++;
            i--;
        }
    }

    else if( j > i){
        while(j >= 0){
            tmp = o1.number_[j] + toAdd - '0';
            if (tmp > 9)
                result_number[k] = '0';
            else {
                result_number[k] = char(tmp + '0');
                toAdd = 0;
            }
            k++;
            j--;
        }
    }

    if(toAdd == 1){
        output.number_ = new char[size+1];

        for(int ii = 0; ii < size; ii++)
            output.number_[ii] = result_number[size - ii];
        output.number_[size] = '\0';

        return output;
    }

    else{
        output.number_ = new char[size];

        for(int ii = 0; ii < size; ii++)
            output.number_[ii] = result_number[size - 1 - ii];
        output.number_[size] = '\0';

        return output;
    }
}


