//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include "IterableIterators.h"


namespace utility {

    class IterableIteratorWrapper{
    public:
        IterableIteratorWrapper (std::unique_ptr<IterableIterator> iterator);

        std::pair<int, std::string> operator*();

        IterableIteratorWrapper &operator++();

        bool operator != (const IterableIteratorWrapper &other);
    private:
        std::unique_ptr<IterableIterator> iterator_;
    };

        class Iterable{
        public:
            IterableIteratorWrapper cbegin() const;

            IterableIteratorWrapper cend() const;

            IterableIteratorWrapper begin() const;

            IterableIteratorWrapper end() const;

            virtual std::unique_ptr<IterableIterator> ConstBegin()const = 0;

            virtual std::unique_ptr<IterableIterator> ConstEnd()const = 0;

            std::pair<std::vector<int>,std::vector<std::string>> zip;

            ~Iterable() = default;
        };

        class Zipper : public Iterable{
        public:
            Zipper (std::vector<int> vs, std::vector<std::string> vi);

            std::unique_ptr<IterableIterator> ConstBegin()const override;

            std::unique_ptr<IterableIterator> ConstEnd()const override;
        };

        class Enumerate : public Iterable{
        public:
            Enumerate (std::vector<std::string> vs);

            std::unique_ptr<IterableIterator> ConstBegin()const override;

            std::unique_ptr<IterableIterator> ConstEnd()const override;
        };

        class Product : public Iterable{
        public:
            Product (std::vector<int> vi, std::vector<std::string> vs);

            std::unique_ptr<IterableIterator> ConstBegin()const override;

            std::unique_ptr<IterableIterator> ConstEnd()const override;

        };

}

#endif //JIMP_EXERCISES_ITERABLE_H
