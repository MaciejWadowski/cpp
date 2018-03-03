#include <iostream>
#include "ReverseString.h"
using namespace std;
int main() {
    string word, new_word;
    cin >> word;
    new_word = reverse(word);
    cout << new_word << endl;
    return 0;
}