//
// Created by wadziuxxx on 4/29/18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>

namespace datastructures {
    class ZipperIterator{
        std::pair<std::string,int> operator*() const;
        ZipperIterator &operator++();
        bool operator!=(const ZipperIterator &other) const;
    private:
        std::vector<std::string, int> data;
    };
    class Zipper {
    public:
        Zipper()=default;
        static Zipper zip(const std::vector<std::string> &vs, const std::vector<int> &vi);
        ZipperIterator begin();
        ZipperIterator end();
    private:
        std::vector<ZipperIterator> zip_;
    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
