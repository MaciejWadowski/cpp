//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H


#include <bits/unique_ptr.h>
#include <vector>
#include "../comparable/Student.h"
#include "StudentRepository.h"

namespace academia {
    class ByFirstName;

    class Query {
    public:
        virtual bool Accept(const Student &student) = 0;
        bool operator () (const Student &student);
        std::vector<Student> FindByQuery(const Query &query);
    };

    class ByFirstName : public Query{
    public:
        bool Accept(const Student &student);
    };

    class ByLastName : public Query{
    public:
        bool Accept(const Student &student);
    };

    class ByOneOfPrograms : public Query{
    public:
        bool Accept(const Student &student);
    };

    class ByYearLowerOrEqualTo : public Query{
    public:
        bool Accept(const Student &student);
    };

    class OrQuery : public Query{
    public:
        bool Accept(const Student &student);
    };

    class AndQuery : public Query{
    public:
        bool Accept(const Student &student);

        AndQuery(std::unique_ptr<Query> left, std::unique_ptr<Query> right)
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
