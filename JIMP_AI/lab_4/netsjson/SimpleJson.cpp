//
// Created by wadziuxxx on 4/12/18.
//

#include "SimpleJson.h"
#include <sstream>

using std::string;


string trickyString(string string_value){
    string output = '"' + string_value + '"';
    for(int i = 1; i < output.size() - 1; i++){
        if(output[i] == '\\' || output[i] == '"' ){
            output.insert(i,1,'\\');
            i++;
        }
    }
    return output;
}

namespace nets{

    JsonValue::JsonValue(int _int_value){
        type = "int";
        int_value = _int_value;
    }

    JsonValue::JsonValue(double _double_value) {
        type = "double";
        double_value = _double_value;
    }

    JsonValue::JsonValue(const std::string &_string_value){
        type = "string";
        string_value = _string_value;
    }

    JsonValue::JsonValue(bool _bool_value) {
        type = "bool";
        bool_value = _bool_value;
    }

    JsonValue::JsonValue(const std::vector<JsonValue> &_vector_value){
        type = "vector";
        vector_value = _vector_value;
    }

    JsonValue::JsonValue(const std::map<std::string, JsonValue> &_map_value){
        type = "map";
        map_value = _map_value;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        if(type != "map") return {};
        else{
            return std::experimental::make_optional(map_value.find(name)->second);
        }
    }

    std::string JsonValue::ToString() const {
        if(type == "int") return std::to_string(int_value);
        else if(type == "double") {
            std::stringstream ss;
            ss << double_value;
            return ss.str();
        }
        else if(type == "string"){
            string output = '"' + string_value + '"';
            for(int i = 1; i < output.size() - 1; i++){
                if(output[i] == '\\' || output[i] == '"' ){
                    output.insert(i,1,'\\');
                    i++;
                }
            }
            return output;
        }
        else if(type == "bool"){
            if(bool_value) return "true";
            else return "false";
        }
        else if( type == "vector"){
            string output = "[";
            for(auto i: vector_value){
                output += i.ToString();
                output += ", ";
            }
            output.pop_back();
            output.pop_back();
            output += "]";
            return output;
        }
        else if(type == "map"){
            string output = "";
            for(auto i: map_value) {
                output += '{' + trickyString(i.first) + ": ";
                output += i.second.ToString() + ", ";
            }
            output.pop_back();
            output.pop_back();
            output += '}';
            return output;
        }

        else return "";

    }
}