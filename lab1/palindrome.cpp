#include <iostream>
#include <string>

bool is_palindrome(std::string str);

int main() {
    int choice;
    bool flag;
    std::string word;
    while (1) {
        std::cout << "Type 1 to check. " << std::endl;
        std::cout << "Press else to exit. " << std::endl;
        std::cin >> choice;
        if (choice != 1) break;
        std::cout << "Enter a word: ";
        std::cin >> word;
        flag = is_palindrome(word);
        if (flag) std::cout << word << " is palindrome.\n\n";
        else std::cout << word << " isn't palindorme.\n\n";
    }
    return 0;
}

bool is_palindrome(std::string str){
    int size = str.size();
    std::string str2 = str;
    int i;
    for ( i = 0 ; i <= size; i++)
        str2[i] = str[size-i-1];
    if (str2 == str) return true;
    else return false;
}