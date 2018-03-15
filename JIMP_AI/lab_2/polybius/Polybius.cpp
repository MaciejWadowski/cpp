//
// Created by maciej on 11.03.18.
//

#include "Polybius.h"
using namespace std;

string PolybiusCrypt(string _message){
    string output = "";
    string message;
    for(int i = 0; i < _message.size(); i++)
        message += tolower(_message[i]);
    char tab[5][5];
    int count = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tab[i][j] = 'a' + count;
            count++;
            if(tab[i][j] == 'i') count++;
        }
    }
    count = 0;
    int size = message.size();
    while(count < size){
        bool flag = true;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(message[count] == tab[i][j]){
                    string str = to_string(i+1);
                    string	str2 = to_string(j+1);
                    output += str;
                    output += str2;
                    flag = false;
                    break;
                }

            }
            if(!flag) break;
        }
        if(message[count] == 'j') output += "24";
        count++;
    }
    return output;
}

string PolybiusDecrypt(string crypted_mes){
    string output = "";
    char tab[5][5];
    int count = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tab[i][j] = 'a' + count;
            count++;
            if(tab[i][j] == 'i') count++;
        }
    }
    count = 0;
    int size = crypted_mes.size();
    while(count+1 < size){
        string c1 = "";
        c1 += crypted_mes[count];
        string c2 = "";
        c2 += crypted_mes[count+1];
        bool flag = true;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(to_string(i+1) == c1 && to_string(j+1) == c2){
                    output += tab[i][j];
                    count+=2;
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
    }
    return output;
}
