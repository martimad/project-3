//
// Created by Madelynn on 6/30/2021.
//

#ifndef PROJECT_1_STRING_H
#define PROJECT_1_STRING_H
#include"Automaton.h"

class String : public Automaton{
private:
    unsigned int inputSize ;
public:
    String() : Automaton(TokenType::STRING) {}

    virtual void S0(const std::string& input){
        inputSize = input.size();
        if(input[index] == '\''){
            ++inputRead;
            ++index;
            S1(input);
        }
        else{Serr();}
    };
    void S1(const std::string& input){
        if(index >= inputSize){return;}
        if(index < input.size()){
            if(input[index]== '\''){
                ++index;
                ++inputRead;
                S2(input);
            }
            else{
                if(input[index] == '\n'){++newLines;}
                ++index;
                ++inputRead;
                S1(input);
            }
        }
        else{Serr();}
    };
    void S2(const std::string& input){
        if(index >= inputSize){return;}
        if(input[index] == '\''){
            ++inputRead;
            ++index;
            S1(input);
        }
        //else{Serr();}
    }
};

#endif //PROJECT_1_STRING_H
