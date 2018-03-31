//
// Created by maciej on 31.03.18.
//

#include "TinyUrl.h"

using ::tinyurl::TinyUrlCodec;
using ::std::unique_ptr;
using std::string;
using std::cout;

int main(){
    unique_ptr<TinyUrlCodec> codec = tinyurl::Init();
    const string url = "https://google.com";
    const string url2 = "https://wikipedia.com";
    const string hash = tinyurl::Encode(url, &codec);
    const string hash2 = tinyurl::Encode(url2, &codec);
    cout << hash << std::endl << hash2 << std::endl;
    cout << tinyurl::Decode(codec, hash) << std::endl << tinyurl::Decode(codec, hash2) << std::endl;
    return 0;
}