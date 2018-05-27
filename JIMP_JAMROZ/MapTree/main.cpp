#include <iostream>
#include "Map.h"
#include "Map.cpp"

int main() {
    Map<int,std::string> o1;
    o1[10] = " wow22owo";
    o1[2] = "xdadasdasd";
    o1[1] = "xda223dasdasd";
    o1[3] = " test";
    o1[5] = " wowowo";
    o1[8] = " wowowo";
    o1[23] = " wowowo";
    o1[241] = " wowowo";
    o1[-12] = " wowowo";
    o1[-1] = " wowowo";
    o1[321] = " wowowo";
    o1[225] = " wowowo";
    o1[0] = " wowowo";

    for(Map<int,std::string>::Iterator i = o1.begin(); i!= o1.end(); ++i) {
        std::cout << i->first << "-- " << i->second << '\n';
    }
    return 0;
}