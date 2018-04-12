//
// Created by wadziuxxx on 4/12/18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
#include <iostream>

namespace nets{
    class View {
    public:
        View(const std::string &line);
        std::string Render(const std::unordered_map<std::string, std::string> &model) const;
    private:
        std::string line;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
