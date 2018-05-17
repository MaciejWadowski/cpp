//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H


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
}


#endif //JIMP_EXERCISES_STUDYYEAR_H
