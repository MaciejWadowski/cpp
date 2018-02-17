#include <iostream>
#include <ctime>
//Niestabilny, w miejscu ,O(nlog(n)), pesymistycznie O(n^2) (gdy posortowane jest w druga strone)
void QuickSort(int tab[], int start, int end);
void Swap(int &a, int &b);

int main() {
    int i, n;
    std::cout << "Enter size: ";
    std::cin >> n;
    int *tab = new int [n];
    srand(time(NULL));

    for ( i = 0; i < n; i++) tab[i] = std::rand()%100 +1;

    QuickSort(tab,0,n);

    for( i = 0; i < n; i++) std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

void QuickSort(int tab[], int start, int end){
    int i, j, piwot;
    piwot = tab[(start+end)/2];
    tab[(start+end)/2] = tab[end-1];
    j = start;
    for ( i = start; i < end; i++){
        if (tab[i] < piwot){
            Swap(tab[i],tab[j]);
            j++;
        }
    }
    tab[end] = tab[j];
    tab[j] = piwot;
    if (start < j-1) QuickSort(tab,start,j-1);
    if (end > j + 1) QuickSort(tab,j+1,end);
}

void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}