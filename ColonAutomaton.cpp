#include "ColonAutomaton.h"
using namespace std;
void ColonAutomaton::S0(const string& input) {
    if (input[index] == ':') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}