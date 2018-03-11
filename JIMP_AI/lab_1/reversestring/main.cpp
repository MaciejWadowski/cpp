//
// Created by maciej on 11.03.18.
//
#include "ReverseString.h"
using namespace std;
int main() {
    string word, new_word;
    cin >> word;
    new_word = reverse(word);
    cout << new_word << endl;
    return 0;
}