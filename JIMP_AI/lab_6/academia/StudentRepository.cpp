//
// Created by wadziuxxx on 4/29/18.
//

#include "StudentRepository.h"


int academia::StudentRepository::StudentCount() const {
    return student.size();
}

academia::StudentRepository::StudentRepository(std::initializer_list<academia::Student> student_list) {
    for(auto i : student_list)
        student.push_back(i);
}

academia::Student &academia::StudentRepository::operator[](std::string id_) {
    for(auto &i : student)
        if (id_ == i.Id()) return i;
    Student st{};
    return st;
}

bool academia::StudentRepository::operator==(const academia::StudentRepository &o1) const {
    if(student.size() != o1.student.size()) return false;
    if(this == &o1) return true;
    for(auto s1 : student){
        for(auto s2 : o1.student){
            if(s1.id == s2.id){
                if(s1 == s2) break;
                else return false;
            }
        }
    }
    return true;
}

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


academia::StudyYear::StudyYear() : data(1){}
academia::StudyYear::StudyYear(int data_):data(data_){}

bool academia::StudyYear::operator==(const academia::StudyYear &o1) const {
    return data == o1.data;
}

bool academia::StudyYear::operator<(const academia::StudyYear &o1) const {
    return data < o1.data;
}

academia::StudyYear::operator int() {
    return data;
}

int academia::StudyYear::getStudyYear() const {
    return data;
}


bool academia::operator==(const int value, const academia::StudyYear &o1) {
    return value == o1.getStudyYear();
}
