//
// Created by wadziuxxx on 4/29/18.
//

#include <set>
#include <algorithm>
#include "WordCounter.h"

datastructures::Counts::Counts() {
    count = 0;
}

datastructures::Counts datastructures::Counts::operator++(int) {
    count = count + 1;
}

datastructures::Counts::operator  int() const{
    return count;
}

datastructures::Counts::Counts(int val) {
    count = val;
}

bool datastructures::Counts::operator==(const datastructures::Counts &o1) const {
    return count == o1.count;
}

bool datastructures::Counts::operator==(const int &val) const {
    return count == val;
}


datastructures::Word::Word() {
    word = "";
}

datastructures::Word::Word(std::string word_) {
    word = word_;
}

std::string datastructures::Word::getWord()const {
    return word;
}

bool datastructures::Word::operator<(const datastructures::Word &o1) const {
    return this->getWord() < o1.getWord();
}

bool datastructures::Word::operator==(const datastructures::Word &o1) const {
    return this->getWord() == o1.getWord();
}

int datastructures::WordCounter::TotalWords() {
    int result = 0;
    if(container.empty()) return 0;
    else{
        for(auto &i: container){
            result += i.second;
        }
    }
    return result;
}

int datastructures::WordCounter::DistinctWords() {
    return container.size();
}

datastructures::WordCounter::WordCounter() {}

datastructures::WordCounter::WordCounter(std::initializer_list<datastructures::Word> list) {
    for(auto i: list){
        if(container.empty()) {
            std::pair<Word,Counts> tmp{i,{}};
            tmp.second++;
            container.push_back(tmp);
        }

        else {
            bool isCounted = false;
            for(auto &j: container){
                if(j.first.getWord() == i.getWord()){
                    j.second++;
                    isCounted = true;
                    break;
                }
            }

            if(!isCounted){
                std::pair<Word,Counts> tmp{i,{}};
                tmp.second++;
                container.push_back(tmp);
            }
        }
    }
}

int datastructures::WordCounter::operator[](std::string word_) const {
    for(auto &i : container)
        if(i.first.getWord() == word_) return int(i.second);

    return 0;
}

std::vector<datastructures::Word> datastructures::WordCounter::Words() const{
    std::vector<Word> ret;
    for(auto i : container)
        ret.push_back(i.first);
    return ret;
}

ostream &operator<<(ostream &s1, const datastructures::WordCounter &o1) {
    std::vector<datastructures::Word> ret = o1.Words();
    std::sort(ret.begin(), ret.end());
    for(auto i: ret)
        s1 << i.getWord() << ", ";
    return s1;
}

bool datastructures::operator==(const std::set<datastructures::Word> &o1,
                                     const std::vector<datastructures::Word> &o2){
    for(auto &i : o1){
        bool isFound = false;
        for(auto &j: o2){
            if(i.getWord() == j.getWord()){
                isFound = true;
                break;
            }
        }
        if(!isFound) return false;
    }
    return true;
}
