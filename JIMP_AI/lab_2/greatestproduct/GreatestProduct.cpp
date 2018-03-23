//
// Created by maciej on 15.03.18.
//

#include "GreatestProduct.h"


int GreatestProduct(const std::vector<int> &numbers, int k) {
    auto *result_elements = new int[k];
    int plus_count = 0;
    int result = 1;
    for (int i = 0; i < numbers.size(); i++) if (numbers[i] >= 0) plus_count++;
    if((plus_count == 0 && k%2 == 1) || (plus_count == numbers.size())) {
        ResultTab(result_elements, numbers, k);
        for (int i = 0; i < k; i++) result = result * result_elements[i];
        delete[]result_elements;
        return result;
    }
    ResultTabv2(result_elements, numbers, k);
    for(int i = 0; i < k; i++) result = result*result_elements[i];
    delete [] result_elements;
    return result;
}

void ResultTab(int result_elements[], const std::vector<int> &numbers, int k){
    int j = 0, minus_count = 0, min = 0;
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
}

void ResultTabv2(int result_elements[], const std::vector<int> &numbers, int k){
    int j = 0, min = 0, minus_count = 0,min_p = 0,min_m = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (j < k) {
            result_elements[j] = numbers[i];
            if (abs(result_elements[min]) > abs(numbers[i])){
              min = j;
              if(numbers[i] > 0 ) min_p = numbers[i];
              else min_m = numbers[i];
            }
            j++;
            if (numbers[i] < 0) minus_count++;
        } else if (abs(numbers[i]) >= abs(result_elements[min])) {
            if (numbers[i] >= 0 && result_elements[min] < 0) minus_count--;
            else if (numbers[i] < 0 && result_elements[min] >= 0) minus_count++;
            result_elements[min] = numbers[i];
            for (int x = 0; x < k; x++) if (abs(result_elements[x]) < abs(numbers[i])) min = x;
            if(numbers[i] > 0 ) min_p = numbers[i];
            else min_m = numbers[i];
        }
    }
    if(minus_count%2 == 1) {
        int count_n_2 = 0, count_p_2 = 0;
        int plus_n = 0, plus_r = 0, minus_n = 0, minus_r = 0, min_plus_val = 0, min_minus_val = 0, check = -1;
        int count_p = 0, count_n = 0;
        for (int i = 0; i < k; i++) {
            if (result_elements[i] == min_m) {
                count_n_2++;
                min_minus_val = i;
            }
            else if (result_elements[i] == min_p) {
                count_p_2++;
                min_plus_val = i;
            }
        }
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] >= 0)plus_n++;
            else minus_n++;
            if(numbers[i] == min_m) count_p++;
            else if(numbers[i] == min_p) count_n++;
        }
        if(count_n_2 != count_n && abs(min_m) >= min_p && min_p != 0) {
            result_elements[min_plus_val] = result_elements[min_minus_val];

            return;
        }
        else if(count_p_2 != count_p && abs(min_m) <= min_p && min_p != 0){
            result_elements[min_minus_val] = result_elements[min_plus_val];
            return;
        }
        if(min_p == 0){
            for(int i = 0; i < numbers.size(); i++)
                if(numbers[i] > 0) min_p = numbers[i];
        }
        for(int i = 0; i < k; i++){
            if(result_elements[i] >= 0){
                plus_r++;
                if(result_elements[min_plus_val] >= result_elements[i]) min_plus_val = i;
                check = 0;
            }
            else{
                minus_r++;
                if(result_elements[min_minus_val] > 0) min_minus_val = i;
                else if(result_elements[min_minus_val] < result_elements[i]) min_minus_val = i;
            }
        }
        if(check == -1){
            int max = numbers[0];
            for(int i = 0; i < numbers.size(); i++){
                if(numbers[i] > max) max = numbers[i];
            }
            result_elements[min_minus_val] = max;
            return;
        }
        if(count_n_2 != count_n && abs(result_elements[min_minus_val]) >= result_elements[min_plus_val]) {
            result_elements[min_plus_val] = result_elements[min_minus_val];

            return;
        }
        else if(count_p_2 != count_p && abs(result_elements[min_minus_val]) <= result_elements[min_plus_val]){
            result_elements[min_minus_val] = result_elements[min_plus_val];

            return;
        }
        int new_element = result_elements[min_minus_val];
        if(plus_n == plus_r) {
            for (int i = 0; i < numbers.size(); i++) {
                if (abs(numbers[i]) < abs(result_elements[min_minus_val]) && abs(numbers[i]) > abs(new_element))new_element = numbers[i];
                if(abs(numbers[i]) == abs(result_elements[min_minus_val]) && count_n_2 < count_n){
                    new_element = numbers[i];
                    break;
                }
            }
            result_elements[min_plus_val] = new_element;
            return;
        }
        else{
            int new_element_2 = 0;
            for(int i = 0; i < numbers.size(); i++){
                if(numbers[i] < result_elements[min_plus_val] && numbers[i] >= 0) if(numbers[i] >= abs(new_element_2)) new_element_2 = numbers[i];
                if(abs(numbers[i]) < abs(result_elements[min_minus_val]) && numbers[i] < 0 && minus_count+1 == k) if(abs(numbers[i]) >= abs(new_element_2)) new_element_2 = numbers[i];
                if(abs(numbers[i]) == abs(result_elements[min_minus_val]) && count_n != count_n_2 && abs(new_element_2 && minus_count+1 == k) <= abs(numbers[i])) new_element_2 = numbers[i];
                if(numbers[i] == result_elements[min_plus_val] && count_p != count_p_2 && abs(new_element) <= numbers[i])  new_element_2 = numbers[i];
            }
            if(new_element_2 == result_elements[min_minus_val] && abs(new_element_2) >= result_elements[min_plus_val]){
                result_elements[min_plus_val] = new_element_2;

            }
            else {
                if(new_element < 0) result_elements[min_minus_val] = min_p;
                result_elements[min_minus_val] = new_element_2;

            }
        }

    }
}


int abs(int val){
    if( val < 0) return -val;
    else return val;
}