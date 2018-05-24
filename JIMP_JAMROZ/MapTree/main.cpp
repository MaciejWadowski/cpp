#include <iostream>
#include "Map.h"
#include "Map.cpp"

int main() {
    Map<int,std::string> o1;
    o1[2] = "xdadasdasd";
    o1[1] = "xda223dasdasd";
    o1[3] = " test";
    o1[5] = " wowowo";
    o1[10] = " wow22owo";
    o1[32] = " wowowo";
    o1[25] = " wowowo";
    for(Iterator<int, std::string> i = o1.begin(); i != o1.end(); ++i){
        std::cout << i->first << " --- " << i->second << '\n';
    }


    return 0;
}