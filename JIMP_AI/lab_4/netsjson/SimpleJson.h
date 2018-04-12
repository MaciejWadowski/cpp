//
// Created by wadziuxxx on 4/12/18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>

namespace nets{
    class JsonValue{
    public:
        JsonValue(int int_value);

        JsonValue(double double_value);

        JsonValue(const std::string &string_value);

        JsonValue(bool bool_value);

        JsonValue(const std::vector<JsonValue> &vector_value);

        JsonValue(const std::map<std::string, JsonValue> &map_value);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;
    private:
        std::string type;
        int int_value;
        double double_value;
        std::string string_value;
        bool bool_value;
        std::vector <JsonValue> vector_value;
        std::map <std::string, JsonValue> map_value;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
