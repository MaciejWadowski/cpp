//
// Created by wadziuxxx on 5/19/18.
//

#include "MovieSubtitles.h"

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) {
    if(frame_per_second < 0){
        throw NegativeFrameAfterShift("frame ", " per second < 0");
    }

    std::regex pattern {R"(\{(\d+)\}\{(\d+)\}(.*))"};
    std::smatch matches;

    double offset_in_sec = offset_in_micro_seconds*0.001;
    int new_frame = int(frame_per_second*offset_in_sec);

    std::string line;
    int nr_line = 1;
    int first_gap_number = 0, second_gap_number = 0;

    while(std::getline(*in,line)){
        if(std::regex_match(line,matches,pattern)){

            std::string other_chars_match = matches[0];
            std::string first_match  = matches[1];
            std::string second_match = matches[2];
            std::string third_match = matches[3];


            if(first_match.empty()) continue;

            first_gap_number = std::stoi(first_match);
            second_gap_number = std::stoi(second_match);

            if(first_gap_number >= second_gap_number){
                throw SubtitleEndBeforeStart(line,std::to_string(nr_line));
            }

            first_gap_number += new_frame;
            second_gap_number += new_frame;

            if(first_gap_number < 0 ){
                throw NegativeFrameAfterShift("Negative ", "frame after shift");
            }

            if(second_gap_number < 0){
                throw NegativeFrameAfterShift("Negative ", "frame after shift");
            }

            *out << '{' << first_gap_number << "}{" << second_gap_number <<'}'<< third_match;

            *out << '\n';
            nr_line++;
        }
        else{
            throw InvalidSubtitleLineFormat(line, std::to_string(nr_line));
        }
    }
}

void
moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                std::ostream *out) {
    if(frame_per_second < 0){
        throw NegativeFrameAfterShift("frame ", " per second < 0");
    }

    std::regex pattern {R"((\d{2}:\d{2}:\d{2}),(\d{3}) --> (\d{2}:\d{2}:\d{2}),(\d{3}))"};
    std::regex pattern_for_timer {R"((\d{2}):(\d{2}):(\d{2}))"};
    std::smatch matches;
    std::smatch matches_for_timer;
    std::string line;
    bool still_text = false;
    int nr_line = 1;
    int how_many_sec = offset_in_micro_seconds/1000;
    int how_many_micro_sec = offset_in_micro_seconds - how_many_sec*1000;


    while(std::getline(*in,line)){

        if(line.size() == 1 && isdigit(line[0])){
            if(line[0] > '2'){
                throw OutOfOrderFrames(line,std::to_string(nr_line));
            }
            *out << line << '\n';
        }

        else if(line.empty()){
            *out << '\n';
            still_text = false;
        }

        else if(still_text){
            *out << line << '\n';
        }

        else{
            still_text = true;
            if(std::regex_match(line,matches,pattern)){

                std::string first_timer = matches[1];
                std::string first_micro_sec = matches[2];
                std::string second_timer = matches[3];
                std::string second_micro_sec = matches[4];
                int seconds,mins,hours,micro_sec, secondsv2, minsv2, hoursv2, micro_secv2;

                if(std::regex_match(first_timer,matches_for_timer, pattern_for_timer)){

                    hours = std::stoi(matches_for_timer[1]);
                    mins = std::stoi(matches_for_timer[2]);
                    seconds = std::stoi(matches_for_timer[3]);

                    micro_sec = std::stoi(first_micro_sec);
                    micro_sec += how_many_micro_sec;

                    if(micro_sec >= 1000) {
                        seconds += 1;
                        micro_sec -= 1000;
                    }

                    seconds += how_many_sec;
                    if(seconds >= 60){
                        mins += seconds/60;
                        seconds -= mins*60;
                        if(mins >= 60){
                            hours += mins/60;
                            mins -= hours*60;
                        }
                    }

                    if(hours < 10)
                        *out << '0' << hours << ':';
                    else
                        *out << hours << ':';
                    if(mins < 10 )
                        *out << '0' << mins << ':';
                    else
                        *out <<  mins << ':';
                    if(seconds < 10)
                        *out << '0' << seconds << ',';
                    else
                        *out << seconds << ',';

                    if(micro_sec < 100){
                        if(micro_sec < 10)
                            *out << "00" << micro_sec;
                        *out << '0' << micro_sec;
                    }
                    else
                        *out << micro_sec;

                    *out << " --> ";

                    if(hours < 0 || mins < 0 || seconds < 0 || micro_sec < 0)
                        throw NegativeFrameAfterShift("Negative ", "frame after shift");
                }
                else{
                    throw InvalidSubtitleLineFormat(line,std::to_string(nr_line));
                }

                if(std::regex_match(second_timer,matches_for_timer, pattern_for_timer)){

                    hoursv2 = std::stoi(matches_for_timer[1]);
                    minsv2 = std::stoi(matches_for_timer[2]);
                    secondsv2 = std::stoi(matches_for_timer[3]);

                    micro_secv2 = std::stoi(second_micro_sec);
                    micro_secv2 += how_many_micro_sec;

                    if(micro_secv2 >= 1000){
                        secondsv2 += 1;
                        micro_secv2 -= 1000;
                    }

                    secondsv2 += how_many_sec;
                    if(secondsv2 >= 60){
                        minsv2 += seconds/60;
                        secondsv2 -= mins*60;
                        if(minsv2 >= 60){
                            hoursv2 += mins/60;
                            minsv2 -= hours*60;
                        }
                    }

                    if(hoursv2 < 10)
                        *out << '0' << hoursv2 << ':';
                    else
                        *out << hoursv2 << ':';
                    if(minsv2 < 10 )
                        *out << '0' << minsv2 << ':';
                    else
                        *out <<  minsv2 << ':';
                    if(secondsv2 < 10)
                        *out << '0' << secondsv2 << ',';
                    else
                        *out << secondsv2 << ',';

                    if(micro_secv2 < 100){
                        if(micro_secv2 < 10)
                            *out << "00" << micro_secv2;
                        *out << '0' << micro_secv2;
                    }
                    else
                        *out << micro_secv2;

                    *out << '\n';

                    if(hours < 0 || mins < 0 || seconds < 0 || micro_sec < 0)
                        throw NegativeFrameAfterShift("Negative ", "frame after shift");

                }
                else{
                    throw InvalidSubtitleLineFormat(line,std::to_string(nr_line));
                }

                if(hours >= hoursv2){
                    if(hours > hoursv2){
                        throw SubtitleEndBeforeStart(line,std::to_string(nr_line));
                    }

                    if(mins >= minsv2){
                        if(mins > minsv2)
                            throw SubtitleEndBeforeStart(line,std::to_string(nr_line));

                        if(seconds >= secondsv2)
                            throw SubtitleEndBeforeStart(line,std::to_string(nr_line));

                    }
                }

                nr_line++;
            }
            else{
                throw InvalidSubtitleLineFormat(line,std::to_string(nr_line));
            }

        }


    }
}

moviesubs::MovieSubtitlesErrorCases::MovieSubtitlesErrorCases(const std::string &message, const std::string &line) : invalid_argument("At line "+line+": "+message) {}

moviesubs::NegativeFrameAfterShift::NegativeFrameAfterShift(const std::string &message, const std::string &num) : MovieSubtitlesErrorCases(message,num){
}

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(const std::string &message, const std::string &line)
        : MovieSubtitlesErrorCases(message, line) {
    num = std::stoi(line);
}

int moviesubs::SubtitleEndBeforeStart::LineAt() const{
    return num;
}

moviesubs::InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(const std::string &message, const std::string &line)
        : MovieSubtitlesErrorCases(message, line) {

}

moviesubs::MissingTimeSpecification::MissingTimeSpecification(const std::string &message, const std::string &line)
        : MovieSubtitlesErrorCases(message, line) {

}

moviesubs::OutOfOrderFrames::OutOfOrderFrames(const std::string &message, const std::string &line)
        : MovieSubtitlesErrorCases(message, line) {

}
