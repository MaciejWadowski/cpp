#include <iostream>
#include <ctime>
// W miejscu, niestabilne, (nlog(n))
int Swap(int &a,int &b);
void HeapSort(int tab[], int n);
void Heap(int tab[],int n);

int main() {
    int i, n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    auto *tab = new int [n+1];
    srand(time(NULL));

    for( i = 1; i <= n; i++) tab[i] = std::rand()%100 + 1;

    HeapSort(tab,n);

    for ( i = 1; i <= n; i++) std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

void HeapSort(int tab[], int n){
    Heap(tab,n);
    int i, j, k, m;
    for ( i = n ; i >= 2; i--){
        Swap(tab[1], tab[i]);
        j = 1;
        k = 2;
        while ( k < i){
            if (( k+1 < i) && (tab[k+1] > tab[k])) m = k+1;
            else m = k;
            if (tab[m] <= tab[j]) break;
            Swap(tab[j],tab[m]);
            j = m;
            k = j*2;
        }
    }
}

void Heap(int tab[], int n){
    int i, j, k, tmp;
    for ( i = 2; i <= n; i++){
        j = i;
        k = j/2;
        tmp = tab[i];
        while((k > 0) && (tmp > tab[k])){
            tab[j] = tab[k];
            j = k;
            k = j/2;
        }
        tab[j] = tmp;
    }
}

int Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}