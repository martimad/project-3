//
// Created by Madelynn on 6/30/2021.
//

#ifndef PROJECT_1_ID_H
#define PROJECT_1_ID_H
#include "Automaton.h"

class ID : public Automaton{
public:
    ID() : Automaton(TokenType::ID) {}

    virtual void S0(const std::string& input){
        //int inputSize = input.size();
        if(isalpha(input[index])){
            ++inputRead;
            ++index;
            S1(input);
        }
        else{Serr();}
    };
    void S1(const std::string& input){
        if(index < input.size()){
            if(isalpha(input[index]) || isdigit(input[index])){
            ++inputRead;
            ++index;
            S1(input);
            }
        }
        else{Serr();}
    };
};


#endif //PROJECT_1_ID_H
