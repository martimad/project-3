#include "ColonDashAutomaton.h"
using namespace std;
void ColonDashAutomaton::S0(const string& input) {
    if (input[index] == ':') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void ColonDashAutomaton::S1(const string& input) {
    if (input[index] == '-') {
        inputRead++;
    }
    else {
        Serr();
    }
}