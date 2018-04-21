//
// Created by wadziuxxx on 4/20/18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
#include <algorithm>

namespace pool{
    class TextPool {
    public:
        TextPool();
        ~TextPool() = default;
        TextPool(std::initializer_list<std::string> words);
        TextPool &operator = (TextPool &&other);
        TextPool (TextPool &&other) noexcept ;
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
    private:
        std::vector <std::string> word;
    };

}


#endif //JIMP_EXERCISES_TEXTPOOL_H
