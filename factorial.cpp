#include <iostream>

int factorial (int);
int rekuFactorial(int);

int main() {
    int n, res;
    std::cout << "Enter a number: ";
    std::cin >> n;
    res = factorial(n);
    std::cout << res << std::endl;
    res = rekuFactorial(n);
    std::cout << res << std::endl;
    return 0;
}

int factorial ( int n){
    if (n==0) return 1;
    int i, res = 1;
    for (i = 1; i<=n; i++)
        res *= i;
    return res;
}

int rekuFactorial (int n){
    if (n==0) return 1;
    else return n*rekuFactorial(n-1);
}