#include <iostream>
#include <string>

int main() {
    using namespace std;
    string s;
    int i, lens;
    cout << "Enter a word: ";
    cin >> s;
    lens = s.size();
    i = lens - 1;
    while ( i > 0 ) {
        if (s.substr(0,i) == s.substr(lens - i,lens)) break;
        i--;
    }
    cout << i << endl;
    return 0;
}
