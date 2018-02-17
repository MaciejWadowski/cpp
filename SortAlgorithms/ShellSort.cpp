#include <iostream>
#include <ctime>
// Niestabilny, w miejscu, O(n^(1.14))
int interspace(int length);
void ShellSort(int tab[], int h, int length);


int main() {
    int i, n, h;
    std::cout << "Enter a number: ";
    std::cin >> n;

    h = interspace(n);
    if (h == 0) h = 1;

    auto *tab = new int [n];
    srand(time(NULL));

    for ( i = 0; i < n; i++) tab[i] = rand()%100 + 1;

    ShellSort(tab,h,n);

    for ( i = 0; i < n; i++) std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

int interspace(int length){
    int tmp = 1, h = 1;
    while ( tmp <= length){
        h = tmp;
        tmp = 3*h + 1;
    }
    return h/9;
}

void ShellSort(int tab[], int h, int length){
    int i, j, x;
    while (h){
        for ( j = length-h-1; j >= 0; j--){               //InsertionSort, tylko podzielony na h
            x = tab[j];
            i = j + h;
            while ((i <= length - 1) && (x > tab[i] )){
                tab[i-h] = tab[i];
                i += h;
            }
            tab[i-h] = x;
        }
        h /= 3;
    }

}
