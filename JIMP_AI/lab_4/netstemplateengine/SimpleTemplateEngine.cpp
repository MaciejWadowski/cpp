//
// Created by wadziuxxx on 4/12/18.
//

#include "SimpleTemplateEngine.h"
#include <regex>

using std::string;
using std::unordered_map;
using std::find;


nets::View::View(const string &line) : line(line) {}

string nets::View::Render(const unordered_map<string, string> &model) const {
    string output = line;
    std::regex pattern ("\\{\\{([^}]*)\\}\\}");
    for (auto x: model) {
        string currField = "{{" + x.first + "}}";
        std::size_t found = 0;
        while(true) {
            found = output.find(currField,found);
            if (found != std::string::npos) output.replace(found, currField.length(), x.second);
            else break;
            found += x.second.length();
        }
    }

    return std::regex_replace(output, pattern, "");
}
