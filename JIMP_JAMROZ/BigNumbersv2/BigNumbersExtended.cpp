//
// Created by Maciej on 11.05.2018.
//

#include "BigNumbers.h"

void fillWithZero(char *container, int size){
    for(int i = 0; i < size;i++)
        container[i] = '0';
}


bool BigNumbersExtended::operator==(const BigNumbersExtended &o1) const {
    if(&o1 == this)
        return true;

    else if(!number_ && !o1.number_)
        return true;

    else if((!number_ && o1.number_) || (number_ && !o1.number_))
        return false;

    else if(strlen(number_) != strlen(o1.number_))
        return false;

    else{
        int i = strcmp(number_,o1.number_); // output from strcmp is <0, 0 or 0>
        return i == 0;
    }


}

bool BigNumbersExtended::operator!=(const BigNumbersExtended &o1) const {
    if(&o1 == this)
        return false;

    else if(!number_ && !o1.number_)
        return false;

    else if((!number_ && o1.number_) || (number_ && !o1.number_))
        return true;

    else if(strlen(number_) != strlen(o1.number_))
        return true;
    else{
        int i = strcmp(number_,o1.number_);
        return i != 0;
    }


}

bool BigNumbersExtended::operator>(const BigNumbersExtended &o1) const {
    if(&o1 == this)
        return false;

    else if(!number_ && !o1.number_)
        return false;

    else if(!number_ && o1.number_)
        return false;

    else if (number_ && !o1.number_)
        return true;

    else if(strlen(number_) < strlen(o1.number_))
        return true;

    else if(strlen(number_) > strlen(o1.number_))
        return false;

    else{
        int i = strcmp(number_,o1.number_);
        return i > 0;
    }
}

bool BigNumbersExtended::operator<(const BigNumbersExtended &o1) const {
    if(&o1 == this)
        return false;

    else if(!number_ && !o1.number_)
        return true;

    else if(!number_ && o1.number_)
        return true;

    else if (number_ && !o1.number_)
        return false;

    else if(strlen(number_) < strlen(o1.number_))
        return false;

    else if(strlen(number_) > strlen(o1.number_))
        return true;

    else{
        int i = strcmp(number_,o1.number_);
        return i < 0;
    }
}

BigNumbersExtended BigNumbersExtended::operator*(const BigNumbersExtended &o1) const {
    if(!number_ && !o1.number_)
        return BigNumbersExtended();

    else if(number_ && !o1.number_)
        return BigNumbersExtended(*this);

    else if(!number_ && o1.number_)
        return BigNumbersExtended(o1);


    int tmp = 0, toAdd = 0, currentNumberLength = 0, size = strlen(number_), secSize = strlen(o1.number_);

    char currentNumber[size+secSize+1], sum[size+secSize+1];

    fillWithZero(sum, size + secSize);
    currentNumber[size+secSize] = sum[size+secSize] = '\0';

    for(int i = 0; i < secSize; i++){
        fillWithZero(currentNumber,size + secSize);

        for(int j = 0; j < size; j++){
            tmp = (number_[size - j - 1] - '0')*(o1.number_[secSize - i - 1] - '0') + toAdd;

            if(tmp > 9){
                toAdd = tmp/10;
                currentNumber[j+i] = char(tmp - toAdd*10 +'0');
            }

            else{
                currentNumber[j+i] = char(tmp + '0');
                toAdd = 0;
            }
            currentNumberLength++;
        }

        if(toAdd > 0){
            currentNumber[currentNumberLength + i] = char(toAdd + '0');
            currentNumberLength++;
            toAdd = 0;
        }

        std::reverse(currentNumber, currentNumber + strlen(currentNumber));

        for(int j = size + secSize - i - 1; j >= size + secSize - currentNumberLength - i; j--){
            tmp = currentNumber[j] - '0' + sum[j] - '0' + toAdd;
            if(tmp > 9){
                sum[j] = char(tmp + '0' - 10);
                toAdd = 1;
            }

            else{
                sum[j] = char(tmp + '0');
                toAdd = 0;
            }
        }
        if(toAdd == 1){
            sum[size+secSize-currentNumberLength-i-1]++;
            toAdd = 0;
        }
        currentNumberLength = 0;
    }

    int zeroCount = 0;
    while(sum[zeroCount] == '0')
        zeroCount++;

    BigNumbersExtended output;
    output.number_ = new char[strlen(sum) - zeroCount + 1];

    for(int i = zeroCount; i < strlen(sum); i++)
        output.number_[i - zeroCount] = sum[i];

    output.number_[strlen(sum) - zeroCount] = '\0';
    return output;
}
