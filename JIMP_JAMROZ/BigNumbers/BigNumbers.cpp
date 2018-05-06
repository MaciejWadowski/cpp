//
// Created by Maciej on 06.05.2018.
//

#include "BigNumbers.h"

BigNumbers::BigNumbers() : str("0"){}

BigNumbers::~BigNumbers() {
    str.clear();
}

BigNumbers::BigNumbers(const char *number) {
    int i = 0;
    bool isNumber = true;
    if(number != nullptr){

        while('\0' != number[i]){
            if(!isdigit(number[i])){
                isNumber = false;
                break;
            }
            i++;
        }

        if(isNumber) {
            str = number;
            i = 0;
            while(str[i] == '0') i++;
            str = str.substr(i, str.size());
        }
        else str = "0";
    }

    else str = "0";
}

BigNumbers::BigNumbers(const BigNumbers &o1) {
    str = o1.str;
}

BigNumbers &BigNumbers::operator=(const BigNumbers &o1){
    str = o1.str;
    return *this;
}

BigNumbers BigNumbers::operator+(const BigNumbers &o1)const {
    std::string output;
    BigNumbers output_;
    int toAdd = 0, tmp;
    int i,j;

    if((str == "0" || str.empty())&&(o1.str == "0" || o1.str.empty())) return output_;


    if(str == "0" || str.empty()) {
        BigNumbers copyOutput{o1};
        return copyOutput;
    }

    if(o1.str == "0" || o1.str.empty()){
        BigNumbers copyOutput{*this};
        return copyOutput;
    }


    for(i = str.length() - 1,  j = o1.str.length() - 1; i >= 0 && j >= 0; i--, j--){
        tmp = str[i] - '0' + o1.str[j] - '0';
        if(tmp + toAdd > 9) {
            output.push_back(char(tmp + '0' - 10 + toAdd));
            toAdd = 1;
        }
        else{
            output.push_back(char(tmp + '0' + toAdd));
            toAdd = 0;
        }
    }

    if(str.length() ==  o1.str.length()) {
        if(toAdd == 1) output.push_back('1');
        Reverse(output,output_);
        return output_;
    }

    if(str.length() > o1.str.length()){
        while(i >= 0 && toAdd == 1){
            if(str[i] + toAdd - '0' > 9) output.push_back(char(str[i] + toAdd - 10));

            else {
                output.push_back(char(str[i] + toAdd ));
                toAdd = 0;
            }
            i--;
        }

        if(toAdd == 1 && i < 0) {
            output.push_back('1');
            Reverse(output, output_);
            return output_;
        }
        else if(i < 0){
            Reverse(output,output_);
            return output_;
        }
        else{
            while(i>=0){
                output.push_back(str[i]);
                i--;
            }
            Reverse(output,output_);
            return output_;
        }

    }
    else{
        while(j >= 0 && toAdd == 1){
            if(o1.str[j] + toAdd - '0' > 9) output.push_back(char(o1.str[j] + toAdd - 10));

            else {
                output.push_back(char(o1.str[j] + toAdd));
                toAdd = 0;
            }
            j--;
        }

        if(toAdd == 1 && j < 0) {
            output.push_back('1');
            Reverse(output, output_);
            return output_;
        }
        else if(j < 0){
            Reverse(output,output_);
            return output_;
        }
        else{
            while(j>=0){
                output.push_back(o1.str[j]);
                j--;
            }
            Reverse(output,output_);
            return output_;
        }
    }

}

void Reverse(std::string o1, BigNumbers &o2){
    o2.str.clear();
    for(std::string::reverse_iterator i = o1.rbegin(); i != o1.rend(); i++)
        o2.str.push_back(*i);
}

std::istream &operator>>(std::istream &s1, BigNumbers &o1) {
    o1.str.clear();
    s1>>o1.str;
    int i = 0;
    bool isNumber = true;

    while('\0' != o1.str[i]){
        if(!isdigit(o1.str[i])){
            isNumber = false;
            break;
        }
        i++;
    }
    if(isNumber){
        i = 0;
        while(o1.str[i] == '0') i++;
        o1.str = o1.str.substr(i,o1.str.length());
    }
    else o1.str = "0";

    return s1;
}

std::ostream &operator<<(std::ostream &s1, BigNumbers &o1){
    if(o1.str.empty()) return s1;
    s1 << o1.str;
    return s1;
}
