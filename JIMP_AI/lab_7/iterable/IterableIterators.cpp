//
// Created by wadziuxxx on 5/17/18.
//

#include "IterableIterators.h"

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    left_ = left_begin;

    right_ = right_begin;

    right_end_ = right_end;

    left_end_ = left_end;
}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    std::pair<int, std::string> actual{*(left_),*(right_)};
    return actual;
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    left_++;
    right_++;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    return (left_ != other->left_ || right_ != other->right_);
}

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin) {
    left_ = left_begin;
    right_ = right_begin;
}
