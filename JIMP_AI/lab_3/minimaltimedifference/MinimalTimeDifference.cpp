//
// Created by maciej on 31.03.18.
//

#include "MinimalTimeDifference.h"

using std::string;
using std::vector;
using std::regex;
using std::smatch;

namespace minimaltimedifference{

    unsigned int ToMinutes(string time_HH_MM){
        smatch matches;
        regex pattern {R"((\d{1,2}):(\d{2}))"};
        if(regex_match(time_HH_MM, matches, pattern)){
            int hours, minutes;
            string hour_str = matches[1];
            string minutes_str = matches[2];
            if(hour_str.size() == 1) hours = int(hour_str[0]-'0');
            else hours = int(hour_str[0]-'0')*10 + int(hour_str[1]-'0');
            minutes = int(minutes_str[0]-'0')*10 + int(minutes_str[1] -'0');

            return hours*60 + minutes;
        }

        return 0;
    }

    unsigned int MinimalTimeDifference(vector<string> times){
        unsigned int min_minutes = 1440;
        int result;
        unsigned int max_minutes = 1440;
        for(int i = 0; i < times.size() - 1; i++){
            for(int j = i; j < times.size() - 1; j++){
                unsigned int first_minutes = ToMinutes(times[i]);
                unsigned int second_minutes = ToMinutes(times[j+1]);
                result = abs(first_minutes - second_minutes);
                if(result < min_minutes ) min_minutes = result;
                result = abs(second_minutes + abs((max_minutes - first_minutes)));
                if(result < min_minutes) min_minutes = result;
                result = abs(first_minutes + abs((max_minutes - second_minutes)));
                if(result < min_minutes) min_minutes = result;
            }
        }

        return min_minutes;
    }
}