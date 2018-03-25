//
// Created by maciej on 15.03.18.
//

#include "XorCypherBreaker.h"
std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary) {
    std::string word = "";
    int tab_a_z[26];
    int count = 0;
    for(int i = 0; i < 26; i++) tab_a_z[i] = 0;

    for(int i = 'a'; i <= 'z'; i++){
        for(int j = 0; j < cryptogram.size(); j++){
            if(isspace(char(cryptogram[j]^i))){
                if (std::find(dictionary.begin(),dictionary.end(), word) != dictionary.end())tab_a_z[count]++;
                word = "";
            }
            else word += char(cryptogram[j]^i);
        }
        word = "";
        count++;
    }
    std::string result = "";
    int max = 0, max_index = 0;
    for(int j = 0; j < key_length; j++) {
        for (int i = 0; i < 26; i++) {
            if (tab_a_z[i] > max) {
                max = tab_a_z[i];
                max_index = i;
                std::cout << tab_a_z[i] << " ";
            }
        }
        result += char(int('a')+max_index);
        tab_a_z[max_index] = 0;
        max = 0;
        max_index = 0;
    }
    return result;
}