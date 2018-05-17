//
// Created by wadziuxxx on 5/17/18.
//

#include "Student.h"

academia::Student::Student() {
    id = "";
    first_name ="";
    last_name = "";
    program = "";
}

academia::Student::Student(std::string id_, std::string first_name_, std::string last_name_, std::string program_,
                           int studyYear_) {
    id = id_;
    first_name = first_name_;
    last_name = last_name_;
    program = program_;
    studyYear.data = studyYear_;
}

bool academia::Student::operator==(const academia::Student &o1) const {
    if(this == &o1) return true;
    return first_name==o1.first_name && last_name == o1.last_name
           && id == o1.id && program == o1.program && studyYear == o1.studyYear;
}

bool academia::Student::operator!=(const academia::Student &o1) const {
    if(first_name != o1.first_name) return true;
    if(last_name != o1.last_name) return true;
    if(id != o1.id) return true;
    if(program != o1.program) return true;
    if(!(studyYear == o1.studyYear)) return true;
    return false;
}

std::string academia::Student::Id() const {
    return id;
}

std::string academia::Student::FirstName() const {
    return first_name;
}

std::string academia::Student::LastName() const {
    return last_name;
}
std::string academia::Student::Program() const {
    return program;
}

academia::StudyYear academia::Student::Year() const {
    return studyYear;
}

void academia::Student::ChangeLastName(std::string last_name_){
    last_name.clear();
    last_name = last_name_;
}



