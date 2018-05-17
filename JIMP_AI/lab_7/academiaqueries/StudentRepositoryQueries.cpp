//
// Created by wadziuxxx on 5/17/18.
//
#include "StudentRepositoryQueries.h"
#include "StudentRepository.h"
#include "../comparable/Student.h"

std::vector<Student> academia::Query::operator()(const academia::Student &student) {
    return FindByQuery(student);
}
