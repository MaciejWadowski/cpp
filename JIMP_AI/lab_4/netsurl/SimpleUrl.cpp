//
// Created by wadziuxxx on 4/5/18.
//

#include "SimpleUrl.h"
#include<regex>
#include<algorithm>
#include <string>

using namespace nets;


SimpleUrl::SimpleUrl(const std::string url) {
    std::regex  pattern {R"((\w+):(\w+)?(@[a-zA-Z.]+)?(\/\/[a-zA-Z.-]+)?(:[0-9]+)?(\/[\/a-zA-Z._0-9,@=!%-:]+)?(\?[a-zA-Z0-9=%&_@.]+)?(.?#[a-zA-Z0-9=!\/_]*)?)"};
    std::smatch matches;
    if (std::regex_match(url, matches, pattern)) {
        scheme = matches[1];
        login = matches[2];
        host = matches[3];
        if(host.empty()){
            host = matches[4];
            if(!host.empty()) host = host.substr(2,host.size());
        }
        else host = host.substr(1,host.size());
        port = matches[5];
        if(!port.empty()) port = port.substr(1,port.size());
        path = matches[6];
        if(!path.empty()){
            if(path[2] != '\\') path = path.substr(1,path.size());
            else path = path.substr(3,path.size());
        }
        query = matches[7];
        if(!query.empty()) query = query.substr(1,query.size());
        fragment = matches[8];
        if(!fragment.empty()){
            if(fragment[0] != '#') fragment = fragment.substr(2,fragment.size());
            else fragment = fragment.substr(1,fragment.size());
        }
    }
}

uint16_t SimpleUrl::Port() const {
    uint16_t int_port = 0;
    for(int i = 0; i < port.size(); i++)
        int_port = int_port*10 + int(port[i]-'0');
    return int_port;
}