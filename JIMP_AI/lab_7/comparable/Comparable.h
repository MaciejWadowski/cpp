//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include "StudyYear.h"
#include "Student.h"

namespace academia {
    class StudentComparator {
    public:
        virtual bool IsLess(const Student &left, const Student &right) = 0;
        bool operator()(const Student &left, const Student &right);
    };

    class ByFirstNameAscending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByFirstNameDescending: public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByLastNameAscending : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyFirst : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyLast : public StudentComparator{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

}


#endif //JIMP_EXERCISES_COMPARABLE_H
