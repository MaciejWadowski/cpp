//
// Created by wadziuxxx on 5/17/18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>
#include <cstring>
#include <iostream>

namespace academia {
    class Pesel {
    public:
        Pesel (const char*);

        void validatePESEL(const char*);

    private:
        const char* pesel;
    };

    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(const std::string &message);
    };

    class InvalidPeselLength :public AcademiaDataValidationError{
    public:
        InvalidPeselLength(const std::string &pesel, size_t length);
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &pesel, int checksum);
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const std::string &pesel);
    };

}


#endif //JIMP_EXERCISES_PESEL_H
