//
// Created by wadziuxxx on 4/12/18.
//

#include "SimpleTemplateEngine.h"
#include <memory>
#include <map>
#include <regex>
using ::std::make_unique;
using nets::View;

int main(){
    const auto maciek = make_unique<View>("My name is {{name}}");
    std::cout << maciek->Render({{"name", "maciek"}});
    std::regex pattern ("\\{\\{")
    return 0;
}