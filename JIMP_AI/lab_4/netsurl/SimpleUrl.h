//
// Created by wadziuxxx on 4/5/18.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include <iostream>
#include <string>
#include <cstdint>

namespace nets {
    class SimpleUrl {
    public:
        std::string Login() const{return login;};
        std::string Host() const{return host;};
        std::string Path() const{return path;};
        uint16_t Port() const;
        std::string Scheme() const{return scheme;};
        std::string Query() const{return query;};
        std::string Fragment() const{return fragment;};
        SimpleUrl(std::string);
    private:
        std::string login;
        std::string host;
        std::string path;
        std::string port;
        std::string scheme;
        std::string query;
        std::string fragment;
    };
}


#endif //JIMP_EXERCISES_SIMPLEURL_H
