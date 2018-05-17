//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "StudyYear.h"
#include <string>
#include <iostream>

namespace academia {
    class Student{
    public:

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
}


#endif //JIMP_EXERCISES_STUDENT_H
