//
// Created by maciej on 15.03.18.
//

#include "XorCypherBreaker.h"
std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary) {
    std::string word = "";
    std::string result_key = "";
    char char_to_cipher;
    int words_count = 0, max_count = 0;
    for(int i = 'a'; i <= 'z'; i++)
           for(int j = 'a'; j <= 'z'; j++)
               for(int k = 'a'; k <= 'z'; k++){

                   char key[] = {i, j, k};

                   for(int l = 0; l < cryptogram.size(); l++){
                       char_to_cipher = char(cryptogram[l]^int(key[l%3]));

                       if(isspace(char_to_cipher)) {
                           if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) words_count++;
                           word = "";
                       }
                       else word += char_to_cipher;
                   }

                   if(words_count > max_count) {
                       max_count = words_count;
                       result_key = "";
                       for(auto c: key) result_key += c;
                   }
                   words_count = 0;
               }
    return result_key;

}