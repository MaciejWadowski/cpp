//
// Created by maciej on 31.03.18.
//

#include "CCounter.h"

using ccounter::Inc;
using std::cout;
using std::endl;
using ccounter::Counts;

int main(){
    std::unique_ptr<ccounter::Counter> counter = ccounter::Init();
    Inc("a", &counter);
    Inc("b", &counter);
    Inc("c", &counter);
    Inc("a", &counter);
    Inc("b", &counter);
    Inc("a", &counter);
    Inc("XDD", &counter);
    cout << Counts(counter, "a") << "->a " << Counts(counter, "b") << "->b "
    << Counts(counter, "XDD") << "->XDD " << Counts(counter, "nothing") << "->nothing" << endl;
    ccounter::SetCountsTo("c", 10, &counter);
    cout << Counts(counter, "c") << endl;
    return 0;
}