//
// Created by maciej on 31.03.18.
//

#include "MinimalTimeDifference.h"

using namespace std;

int main(){

    vector<string> hours = {"23:59", "21:22", "01:23"};
    cout << minimaltimedifference::MinimalTimeDifference(hours);
    return 0;
}