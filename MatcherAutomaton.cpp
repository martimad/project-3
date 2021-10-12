//
// Created by Madelynn on 6/29/2021.
//
using namespace std;
#include "MatcherAutomaton.h"



void MatcherAutomaton::S0(const string& input) {
    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
    }
    if (isMatch) {
        inputRead = toMatch.size();
        //need to update lines read
    }
}