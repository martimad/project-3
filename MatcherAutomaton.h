//
// Created by Madelynn on 6/29/2021.
//

#ifndef PROJECT_1_MATCHERAUTOMATON_H
#define PROJECT_1_MATCHERAUTOMATON_H
#include "Automaton.h"
using namespace std;
class MatcherAutomaton: public Automaton
{
private:
    string toMatch;
public:
    //MatcherAutomaton();
    MatcherAutomaton(string toMatch, TokenType tokenType){
        this->toMatch = toMatch;
        this->type = tokenType;
    };
    ~MatcherAutomaton();
    //int Start(const string& input);
    virtual void S0(const std::string& input);
};


#endif //PROJECT_1_MATCHERAUTOMATON_H
