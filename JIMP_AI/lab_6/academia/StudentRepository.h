//
// Created by wadziuxxx on 4/29/18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <iostream>
#include <vector>
#include <type_traits>

namespace academia{
    class StudyYear{
    public:
        friend class Student;
        StudyYear(){data = 1;};
        explicit StudyYear(int data_){data = data_;};
        bool operator == (const StudyYear &o1)const{return data == o1.data;};
        bool operator < (const StudyYear &o1) const{return data < o1.data;};
        operator int(){return data;};
        int getStudyYear()const{return data;}
    private:
        int data;
    };
    bool operator==(const int value, const StudyYear &o1){return value == o1.getStudyYear();};
    class Student{
    public:
        Student();
        Student(std::string id_, std::string first_name_,std::string last_name_, std::string program_, int studyYear_);
        std::string Id()const{return id;};
        std::string FirstName()const{return first_name;};
        std::string LastName()const{return last_name;};
        std::string Program()const{return program;};
        StudyYear Year()const{return studyYear;};
        void ChangeLastName(std::string last_name_){last_name = last_name_;};
        bool operator == (const Student &o1) const;
        bool operator != (const Student &o1) const;
    private:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear studyYear;
    };


    class StudentRepository{
    public:
        StudentRepository() = default;
        StudentRepository(std::initializer_list<Student> student_list);
        int StudentCount()const;
        Student operator[](std::string id_)const;
        bool operator == (const StudentRepository &o1)const;
    private:
        std::vector<Student> student;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
