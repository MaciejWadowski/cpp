#include <iostream>
#include <ctime>
// W miejscu, niestabilny, O(n)
void SelectionSort(int tab[], int length);
int MinValue(int tab[], int start, int end);

int main() {
    int i, n;
    std::cout << "Enter a number of elements: ";
    std::cin >> n;
    int *tab = new int [n];
    srand(time(NULL));

    for ( i = 0; i < n; i++) tab[i] = std::rand()%100 + 1;

    SelectionSort(tab, n);

    for ( i = 0; i < n; i++) std::cout << tab[i] << " ";

    delete [] tab;
    return 0;
}

void SelectionSort(int tab[], int length){
    int i, j, tmp;
    for ( i = 0; i < length; i++){
        j = MinValue(tab, i, length);
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int MinValue(int tab[], int start, int end){
    int i, min, min_iter;
    min = tab[start];
    min_iter = start;
    for ( i = start; i < end; i++){
        if (min > tab[i]){
            min = tab[i];
            min_iter = i;
        }
    }
    return min_iter;
}