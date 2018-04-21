//
// Created by wadziuxxx on 4/20/18.
//

#include "TextPool.h"

using namespace pool;
using namespace std;

TextPool::TextPool(initializer_list<string> words) {
    for(auto &i: words)
        if(!(find(word.begin(), word.end(),i) != word.end()))
            word.push_back(i);
}

TextPool &TextPool::operator=(TextPool &&other) {
    if (this == &other) return *this;
    for (auto &i: other.word) word.push_back(i);
    std::vector<string>().swap(other.word);
}

TextPool::TextPool(TextPool &&other) noexcept {
    for(auto &i: other.word) word.push_back(i);
    std::vector<string>().swap(other.word);
}

std::experimental::string_view TextPool::Intern(const std::string &str) {
    experimental::string_view tmp;
    for(auto &i : word) if(i == str){
        tmp = i;
        return tmp;
    }
    word.push_back(str);
    tmp = word.back();
    return tmp;
}

size_t TextPool::StoredStringCount() const {
    return word.size();
}

TextPool::TextPool(){
    std::vector <string>().swap(word);
};

