//
// Created by wadziuxxx on 5/1/18.
//

#include "ArrayFill.h"

arrays::UniformFill::UniformFill() {
    value = 0;
}

arrays::UniformFill::UniformFill(int value_) {
    value = value_;
}

int arrays::UniformFill::Value(int index) const {
    return value;
}

void arrays::FillArray(size_t size, const arrays::ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for (size_t i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}

arrays::IncrementalFill::IncrementalFill(int value_) {
    value = value_;
    incrementation = 1;
}

arrays::IncrementalFill::IncrementalFill(int value_, int inc_) {
    value = value_;
    incrementation = inc_;
}

int arrays::IncrementalFill::Value(int index) const {
    return value + incrementation*index;
}


arrays::SquaredFill::SquaredFill() {
    a = 1;
    b = 0;
}

arrays::SquaredFill::SquaredFill(int a_) {
    a = a_;
    b = 0;
}

arrays::SquaredFill::SquaredFill(int a_, int b_) {
    a = a_;
    b = b_;
}

int arrays::SquaredFill::Value(int index) const {
    return a*index*index + b;
}
