//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H


#include <vector>
#include "../comparable/Student.h"
#include "StudentRepositoryQueries.h"
#include "StudentRepository.h"

namespace academia{

    class StudentRepository{
    public:

        StudentRepository() = default;

        StudentRepository(std::initializer_list<Student> student_list);

        int StudentCount()const;

        Student &operator[](std::string id_);

        bool operator == (const StudentRepository &o1)const;

        std::vector<Student> FindByQuery(const Query &query);
    private:
        std::vector<Student> student;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
