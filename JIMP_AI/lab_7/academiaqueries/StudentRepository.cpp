//
// Created by wadziuxxx on 5/17/18.
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
