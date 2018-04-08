//
// Created by wadziuxxx on 4/7/18.
//

#include "Name.h"
using ::std::experimental::optional;
using ::std::experimental::make_optional;
using std::string;

namespace model {
    Name::Name(const std::string &first_names_surname) {
        std::regex pattern {R"((\w+)\s+(\w+)(\s+\w+)?(\s+\w+)?(\s+\w+)?)"};
        std::smatch matches;
        int count = 0;
        string word;
        if(std::regex_match(first_names_surname, matches, pattern)){
            first_name_ = matches[1];
            for(int i = 3; i <= 5; i++){
                word = matches[i];
                if(!word.empty()) count++;
            }
            if(count == 0) last_name_ = matches[2];
            if(count == 1) {
                second_name_ = matches[2];
                last_name_ = matches[3];
                int i = 0;
                while(isspace(last_name_[i]))i++;
                last_name_ = last_name_.substr(i,last_name_.size());
            }
            if(count == 2){
                second_name_ = matches[2];
                third_name_ = matches[3];
                last_name_ = matches[4];
                int i = 0;
                while(isspace(last_name_[i]))i++;
                last_name_ = last_name_.substr(i,last_name_.size());
                i = 0;
                while(isspace(third_name_[i]))i++;
                third_name_ = third_name_.substr(i,third_name_.size());
            }
        }
    }
    optional<string> Name::SecondName() const {
        if(second_name_.empty()) return {};
        else return make_optional(second_name_);
    }

    optional<string> Name::ThirdName() const {
        if(third_name_.empty()) return {};
        else return make_optional(third_name_);
    }

    string Name::ToFullInitials() const {
        string Initials = "";
        Initials = Initials + first_name_[0] + '.';
        if (SecondName()) Initials = Initials + ' ' + second_name_[0] + '.';
        if(ThirdName()) Initials = Initials + ' ' + third_name_[0] + '.';
        return Initials + ' ' + last_name_[0] + '.';
    }

    string Name::ToFirstNamesInitials() const {
        string Initials = "";
        Initials = Initials + first_name_[0] + '.';
        if(SecondName()) Initials = Initials + ' ' + second_name_[0] + '.';
        if(ThirdName()) Initials = Initials + ' ' + third_name_[0] + '.';
        return Initials + ' ' + last_name_;
    }

    string Name::ToSurnameNames() const {
        string SurnameNames = last_name_;
        SurnameNames = SurnameNames + ' ' + first_name_;
        if(SecondName()) SurnameNames = SurnameNames + ' ' + second_name_;
        if(ThirdName()) SurnameNames = SurnameNames + ' ' + third_name_;
        return SurnameNames;
    }

    string Name::ToNamesSurname() const {
        string NamesSurname = first_name_;
        if(SecondName()) NamesSurname = NamesSurname + ' ' + second_name_;
        if(ThirdName()) NamesSurname = NamesSurname + ' ' + third_name_;
        return NamesSurname + ' ' + last_name_;
    }

    bool Name::IsBeforeByFirstName(const model::Name &other) const {
        int i = 0;
        while(i < first_name_.size()){
            if(first_name_[i] < other.first_name_[i]) return true;
            else if(first_name_[i] > other.first_name_[i]) return false;
             i++;
        }
        return true;
    }

    bool Name::IsBeforeBySurname(const model::Name &other) const {
        int i = 0;
        while(i < last_name_.size()){
            if(last_name_[i] < other.last_name_[i]) return true;
            else if(last_name_[i] > other.last_name_[i]) return false;
            i++;
        }
        return true;
    }



}