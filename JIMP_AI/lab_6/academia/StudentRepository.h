//
// Created by wadziuxxx on 4/29/18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <iostream>
#include <vector>

namespace academia{
    class StudyYear{
    public:
        friend class Student;
        StudyYear();
        explicit StudyYear(int data_);
        bool operator == (const StudyYear &o1)const;
        bool operator < (const StudyYear &o1) const;
        operator int();
        int getStudyYear()const;
    private:
        int data;
    };
    inline bool operator==(const int value, const StudyYear &o1);
    class Student{
    public:
        friend class StudentRepository;
        Student();
        Student(std::string id_, std::string first_name_,std::string last_name_, std::string program_, int studyYear_);
        std::string Id()const;
        std::string FirstName()const;
        std::string LastName()const;
        std::string Program()const;
        StudyYear Year()const;
        void ChangeLastName(std::string last_name_);
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
        Student &operator[](std::string id_);
        bool operator == (const StudentRepository &o1)const;
    private:
        std::vector<Student> student;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
