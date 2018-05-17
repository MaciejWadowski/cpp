//
// Created by wadziuxxx on 5/17/18.
//

#include "Comparable.h"

bool academia::StudentComparator::operator()(const academia::Student &left, const academia::Student &right) {
    return IsLess(left,right);
}

bool academia::ByFirstNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName() < right.FirstName();
}

bool academia::ByFirstNameDescending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName() > right.FirstName();
}

bool academia::ByLastNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.LastName() < right.LastName();
}

bool academia::ByProgramAscendingEmptyFirst::IsLess(const academia::Student &left, const academia::Student &right) {
    if(left.Program() == "") return true;
    else if(left.Program() == right.Program()) return false;

    return left.Program() < right.Program();
}

bool academia::ByProgramAscendingEmptyLast::IsLess(const academia::Student &left, const academia::Student &right) {
    if(left.Program() == "" ) return false;
    else if(left.Program() == right.Program()) return false;

    return left.Program() < right.Program();
}
