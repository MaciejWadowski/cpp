//
// Created by wadziuxxx on 4/5/18.
//

#include "SimpleUrl.h"

int main(){
    nets::SimpleUrl FirstUrl{"https://google.com"};
    nets::SimpleUrl SecondUrl{"mailto:someone@example.com?subject=This%20is%20the%20subject&cc=someone_else@example.com&body=This%20is%20the%20body"};
    std::cout << FirstUrl.Scheme() << " " <<  FirstUrl.Host() << std::endl;
    std::cout << SecondUrl.Scheme() << " " << SecondUrl.Login() << " " << SecondUrl.Host() << " " << SecondUrl.Query();
    return 0;
}