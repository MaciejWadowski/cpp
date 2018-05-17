//
// Created by wadziuxxx on 5/17/18.
//


#include "Pesel.h"

academia::Pesel::Pesel(const char *pesel_) {
    validatePESEL(pesel_);
}

void academia::Pesel::validatePESEL(const char *o1) {
    std::string pesel_str = o1;
    if(strlen(o1) != 11){
        throw InvalidPeselLength(pesel_str, pesel_str.size());
    }

    for(int i = 0; i <= 10; i++){
        if(o1[i] < '0'|| o1[i] > '9'){
            throw InvalidPeselCharacter(pesel_str);
        }
    }

    int sum = 9*int(o1[0]-'0') + 7*int(o1[1]-'0') + 3*int(o1[2] - '0') + int(o1[3] - '0')
              + 9*int(o1[4] - '0') + 7*int(o1[5] - '0') + 3*int(o1[6] - '0')
              + int(o1[7] - '0') + 9*int(o1[8]-'0') + 7*int(o1[9] - '0');

    if(sum%10 != o1[10]-'0'){
        throw InvalidPeselChecksum(pesel_str, sum);
    }

    pesel = o1;
}


academia::AcademiaDataValidationError::AcademiaDataValidationError(const std::string &message) : runtime_error(message)  {
}

academia::InvalidPeselLength::InvalidPeselLength(const std::string &pesel, size_t length)
        : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " + std::to_string(length)) {
}

academia::InvalidPeselChecksum::InvalidPeselChecksum(const std::string &pesel, int checksum)
        : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum)){

}

academia::InvalidPeselCharacter::InvalidPeselCharacter(const std::string &pesel)
        : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set") {

}
