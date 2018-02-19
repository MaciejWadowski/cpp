#include <iostream>
#include <ctime>
int main() {
    using namespace std;
    int i;
    string s;
    string p;
    srand((unsigned)time(NULL));
    s = "";
    for ( i = 0; i < 80; i++) s += char(65 + rand()%3);
    p = "";
    for (i = 0; i < 3; i++) p += char(65 + rand()%3);

    cout << s << endl;
    cout << p << endl;

    for ( i = 0; i < 78; i++) cout << ( p == s.substr(i,3) ? "1" : "0"); // s.substr(i,3) od miejsca i 3 znaki..

    return 0;
}
