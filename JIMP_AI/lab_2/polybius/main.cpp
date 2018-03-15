//
// Created by maciej on 11.03.18.
//

#include "Polybius.h"

using namespace std;

int main(int argc, char *argv[]){
    string word;
    if(argc >= 4){
        string str(argv[3]);
        ofstream output_file(argv[2], ios_base::in | ios_base::app);
        ifstream input_file(argv[1]);
        if(!input_file) exit(-1);
        if(!output_file) exit(-2);
        if(str == "1") {
            while (input_file >> word) {
                word = PolybiusCrypt(word);
                output_file << word;
            }
        }
        else if(str == "0"){
            while(input_file >> word){
                word = PolybiusDecrypt(word);
                output_file << word;
            }
        }
        output_file.close();
        input_file.close();
    }
    return 0;
}