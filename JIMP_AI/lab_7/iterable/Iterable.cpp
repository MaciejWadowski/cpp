//
// Created by wadziuxxx on 5/17/18.
//

#include "Iterable.h"

using namespace std;


namespace utility{

    Zipper::Zipper(std::vector<int> vs, std::vector<std::string> vi) {
        if(vs.size() > vi.size()){
            while(vs.size() > vi.size())
                vi.push_back(vi.back());
        }

        else if( vs.size() < vi.size()){
            while(vs.size() < vi.size())
                vs.push_back(vs.back());
        }

        zip = make_pair(vs,vi);
    }

    std::unique_ptr<IterableIterator> Zipper::ConstBegin() const {
        auto zip_ = ZipperIterator(zip.first.begin(),zip.second.begin());
        return std::make_unique<ZipperIterator>(zip_);
    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        auto zip_ = ZipperIterator(zip.first.end(),zip.second.end());
        return std::make_unique<ZipperIterator>(zip_);
    }


    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator) {
        iterator_ = std::move(iterator);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() {
        return iterator_->Dereference();
    }

    IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
        iterator_->Next();
        return *this;
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return iterator_->NotEquals(other.iterator_);
    }

    IterableIteratorWrapper Iterable::cbegin() const {
        return IterableIteratorWrapper{ConstBegin()};
    }

    IterableIteratorWrapper Iterable::cend() const {
        return IterableIteratorWrapper{ConstEnd()};
    }

    IterableIteratorWrapper Iterable::begin() const {
        return IterableIteratorWrapper{cbegin()};
    }

    IterableIteratorWrapper Iterable::end() const {
        return IterableIteratorWrapper{cend()};
    }

    Enumerate::Enumerate(std::vector<std::string> vs) {
        std::vector<int> vi;
        for(int i = 0; i < vs.size(); i++){
            vi.push_back(i+1);
        }

        zip = make_pair(vi,vs);
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        auto zip_ = ZipperIterator(zip.first.begin(), zip.second.begin());
        return make_unique<ZipperIterator>(zip_);
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        auto zip_ = ZipperIterator(zip.first.end(), zip.second.end());
        return make_unique<ZipperIterator>(zip_);
    }

    std::unique_ptr<IterableIterator> Product::ConstEnd() const {
        auto zip_ = ZipperIterator(zip.first.end(), zip.second.end());
        return make_unique<ZipperIterator>(zip_);
    }

    std::unique_ptr<IterableIterator> Product::ConstBegin() const {
        auto zip_ = ZipperIterator(zip.first.begin(), zip.second.begin());
        return make_unique<ZipperIterator>(zip_);
    }

    Product::Product(std::vector<int> vi, std::vector<std::string> vs) {
        std::vector<int> vi_;
        std::vector<string> vs_;
        for(int i = 0; i < vi.size(); i++){
            for(int j = 0; j < vs.size(); j++){
                vs_.push_back(vs[j]);
                vi_.push_back(vi[i]);
            }
        }

        zip = make_pair(vi_,vs_);
    }
}
