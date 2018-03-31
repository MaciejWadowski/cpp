//
// Created by maciej on 31.03.18.
//

#include "MinimalTimeDifference.h"

using std::string;
using std::vector;
using std::regex;

namespace minimaltimedifference{

    unsigned int ToMinutes(string time_HH_MM){
        if (time_HH_MM.size() == 4){
            char hours = time_HH_MM[0];
            string minutes = time_HH_MM.substr(2, 4);
            unsigned int hour, minut;

            hour = int(hours - '0');
            minut = int(minutes[0] - '0') * 10 + int(minutes[1] - '0');

            return hour*60 + minut;
        }
        else {
            string hours = time_HH_MM.substr(0, 2);
            string minutes = time_HH_MM.substr(3, 5);
            unsigned int hour, minut;

            hour = int(hours[0] - '0') * 10 + int(hours[1] - '0');
            minut = int(minutes[0] - '0') * 10 + int(minutes[1] - '0');

            return hour * 60 + minut;
        }
    }

    unsigned int MinimalTimeDifference(vector<string> times){
        unsigned int min_minutes = 1440;
        int result;
        unsigned int max_minutes = 1440;
        for(int i = 0; i < times.size() - 1; i++){
            for(int j = i; j < times.size() - 1; j++){
                unsigned int first_minutes = ToMinutes(times[i]);
                unsigned int second_minutes = ToMinutes(times[j+1]);
                std::cout << first_minutes << " " << second_minutes << std::endl;
                result = abs(first_minutes - second_minutes);
                if(result < min_minutes ) min_minutes = result;
                result = abs(second_minutes - abs((max_minutes - first_minutes)));
                if(result < min_minutes) min_minutes = result;
            }
        }

        return min_minutes;
    }
}