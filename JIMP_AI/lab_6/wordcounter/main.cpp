//
// Created by wadziuxxx on 4/29/18.
//

#include "WordCounter.h"

ostream &operator<<(ostream &s1, const datastructures::WordCounter &o1) {
    std::vector<datastructures::Word> ret = o1.Words();
    std::sort(ret.begin(), ret.end());
    for(auto i: ret)
        s1 << i.getWord() << ", ";
    return s1;
}

using namespace datastructures;

int main(){
    WordCounter container{{Word{"abc"},Word{"zbysc"},Word{"hehehe"}}};
    std::cout << container;
    return 0;
}