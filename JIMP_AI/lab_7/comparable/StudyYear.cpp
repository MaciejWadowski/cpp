//
// Created by wadziuxxx on 5/17/18.
//

#include "StudyYear.h"

academia::StudyYear::StudyYear() : data(1){}

academia::StudyYear::StudyYear(int data_):data(data_){}

bool academia::StudyYear::operator==(const academia::StudyYear &o1) const {
    return data == o1.data;
}

bool academia::StudyYear::operator<(const academia::StudyYear &o1) const {
    return data < o1.data;
}

academia::StudyYear::operator int() {
    return data;
}

int academia::StudyYear::getStudyYear() const {
    return data;
}