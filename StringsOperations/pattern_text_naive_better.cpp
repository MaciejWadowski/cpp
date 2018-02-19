#include <iostream>
#include <ctime>

int main() {
    using namespace std;
    string s, p;
    srand((unsigned)time(NULL));
    int i,j,lens, lenp;

    s = "";
    for ( i = 0; i < 80; i++) s += char(65 + rand()%3);
    p = "";
    for( i = 0; i < 3; i++) p += char(65 + rand()%3);
    cout << s << endl << p << endl;
    lens = s.size();
    lenp = p.size();
    s += 'X';   //wartowniki
    p += 'Y';

    for ( i = 0; i < lens - lenp; i++) {
        j = 0;
        while (s[i+j] == p[j]) j++;  //nie porownoje za kazdym razem, dopiero jak ta sama litera
        if ( j == lenp) cout << i << " ";
    }
    return 0;
}
