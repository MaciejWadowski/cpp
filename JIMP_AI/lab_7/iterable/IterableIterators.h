//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_ITERABLEITERATORS_H
#define JIMP_EXERCISES_ITERABLEITERATORS_H

#include <string>
#include <memory>
#include <vector>

namespace utility {
    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference()const= 0;

        virtual IterableIterator &Next() = 0;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other)const= 0;

        virtual ~IterableIterator() = default;

        std::vector<int>::const_iterator left_;
        std::vector<std::string>::const_iterator right_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;
    };

    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        ZipperIterator(std::vector<int>::const_iterator left_begin, std::vector<std::string>::const_iterator right_begin);

        std::pair<int, std::string> Dereference() const override;

        IterableIterator &Next() override ;

        bool NotEquals(const std::unique_ptr<IterableIterator> &other)const override;

        ~ZipperIterator() override = default;

    };

}



#endif //JIMP_EXERCISES_ITERABLEITERATORS_H
