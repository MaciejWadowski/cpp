#include <iostream>
#include <ctime>
// Stabilne, w miejscu, op O(n), normalnie O(n^2)
void BubbleSort(int tab[], int length);

int main() {
    int n, i;
    srand(time(NULL));
    std::cout << "Enter a number of elements: ";
    std::cin >> n;
    int *tab = new int [n];

    for (i = 0; i < n; i++)
        tab[i] = std::rand()%100 +1;

    BubbleSort(tab,n);

    for (i = 0; i < n; i++)
        std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

void BubbleSort(int tab[], int length) {
    int i, min, max, p;
    min = 1;
    max = length - 1;
    do{
        p = -1;
        for (i = min; i < max; i++) {
            if (tab[i] > tab[i + 1]) {
                int tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                if ( p < 0 ) min = i;
                p = i;
            }
        }
        if (min) min--;
        max = p;
    }while (p >= 0);
}


