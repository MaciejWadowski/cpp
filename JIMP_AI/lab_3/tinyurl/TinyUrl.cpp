//
// Created by maciej on 31.03.18.
//

#include "TinyUrl.h"

using std::string;
using std::unique_ptr;
using std::make_unique;
using std::array;
using std::map;
using std::pair;

string ArrayToString(array<char, 6> to_convert){
    string return_value = "";
    for(auto c : to_convert)
        return_value += c;
    return return_value;
}

array<char, 6> StringToArray(string to_convert){
    array<char, 6> new_array;
    for(int i = 0; i < 6; i++)
        new_array[i] = to_convert[i];
    return new_array;
};



namespace tinyurl{

    unique_ptr<TinyUrlCodec> Init(){
        auto codec = make_unique<TinyUrlCodec>();
        return codec;
    }

    void NextHash(array<char, 6> *state){
        string baseDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string prev_hash = ArrayToString(*state);
        string new_hash = "000001";
        int add = 1;
        for(int i = prev_hash.size() - 1; i >= 0; i--)
            for(int j = 0; j < baseDigits.size(); j++) {
                if (prev_hash[i] == baseDigits[j] && add == 1){
                    if(prev_hash[i] != 'z') {
                        new_hash[i] = char(baseDigits[j+add]);
                        add = 0;
                    }
                    else new_hash[i] = '0';
                    break;
                }
                else if(add == 0) new_hash[i] = prev_hash[i];
            }
        int i = 0;
        for(auto &c: *state){
            c = new_hash[i];
            i++;
        }
    }

    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec){
        pair<string, string> new_element;
        if((*codec)->data.empty()){
            new_element ={"000000", url};
            (*codec)->data.insert(new_element);
            return "000000";
        }

        string last_hash = (*codec)->data.rbegin()->first;
        string new_hash;
        array<char, 6> arr_hash = StringToArray(last_hash);
        NextHash(&arr_hash);
        new_hash = ArrayToString(arr_hash);
        new_element = {new_hash, url};
        (*codec)->data.insert(new_element);

        return new_hash;
    }

    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash){
            return codec->data.find(hash)->second;
    }

}