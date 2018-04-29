//
// Created by wadziuxxx on 4/29/18.
//

#include "Zipper.h"

static datastructures::Zipper datastructures::Zipper::zip(const std::vector<std::string> &vs, const std::vector<int> &vi) {
    zip_.push_back(vs,vi);
}

std::pair<std::string, int> datastructures::ZipperIterator::operator*() const {
    return std::pair<std::string, int>();
}
