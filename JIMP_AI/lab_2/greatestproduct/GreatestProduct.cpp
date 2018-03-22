//
// Created by maciej on 15.03.18.
//

#include "GreatestProduct.h"

int abs(int val){
    if( val < 0) return -val;
    else return val;
}

int GreatestProduct(const std::vector<int> &numbers, int k){
    auto *result_elements = new int[k];
    int min = 0;
    int j = 0, minus_count = 0;
    int result = 1;
    for(int i = 0; i < numbers.size(); i++){
        if(j < k ) {
            result_elements[j] = numbers[i];
            if (numbers[i] < 0) minus_count++;
            if (result_elements[min] > result_elements[j]) min = j;
            j++;
        }
        else if(numbers[i] > result_elements[min]){
            if(numbers[i] > 0 && result_elements[min] < 0) minus_count--;
            else if(numbers[i] < 0 && result_elements[min] > 0) minus_count++;
            result_elements[min] = numbers[i];
            for(int p = 0; p < k; p++) if(result_elements[p] < result_elements[min]) min = p;
        }
    }


    for(int i = 0; i < k; i++) result = result*result_elements[i];

    delete [] result_elements;

    return result;
}
