//
// Created by wadziuxxx on 4/29/18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using std::ostream;

namespace datastructures {


    class Counts{
    public:
        Counts();
        explicit Counts(int);
        Counts operator++(int);
        operator int()const;
        bool operator==(const Counts&) const;
        bool operator==(const int&) const;
    private:
        int count;
    };

    class Word{
    public:
        Word();
        Word(std::string word_);
        std::string getWord()const;
        bool operator<(const Word&) const;
        bool operator==(const Word&) const;
    private:
        std::string word;
    };

    bool operator ==(const std::set<Word> &o1, const std::vector<Word> &o2);

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list);
        int DistinctWords();
        int TotalWords();
        std::vector<Word> Words()const;
        int operator [](std::string word_)const;
    private:
        friend ostream &operator << (ostream &s1,const WordCounter &o1);
        std::vector<std::pair<Word,Counts>> container;
    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
