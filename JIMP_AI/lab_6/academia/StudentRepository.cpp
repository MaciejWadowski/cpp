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

academia::Student academia::StudentRepository::operator[](std::string id_) const {
    for(auto i : student)
        if (id_ == i.Id()) return i;
    return Student{};
}

bool academia::StudentRepository::operator==(const academia::StudentRepository &o1) const {
    if(student.size() != o1.student.size()) return false;
    for(int i = 0; i < student.size();i++)
        if(student != o1.student) return false;
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


