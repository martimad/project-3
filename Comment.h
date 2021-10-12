//
// Created by Madelynn on 6/29/2021.
//

#ifndef PROJECT_1_COMMENT_H
#define PROJECT_1_COMMENT_H
#include "Automaton.h"

class Comment : public Automaton
{
private:

public:
    Comment() : Automaton(TokenType::COMMENT) {}  // Call the base constructor
    void S0(const std::string& input){
        unsigned int inputSize = input.size();
        if (input[index] == '#') {
            inputRead = 1;
            ++index;
            if(input[index] == '|' && index < inputSize){
                ++index;
                ++inputRead;
                if(index >= inputSize){return;}
                BlockComment(input);
            }
            else{
                //if newline increment
                while(input[index] != '\n' && index < inputSize){
                    ++inputRead;
                    ++index;
                }
                if(index >= inputSize){return;}
            }
        }
        else {Serr();}
    };
    void BlockComment(const std::string& input){
        unsigned int inputSize = input.size();
        while(input[index] != '|'){
            if(index >= inputSize){
                Serr();
            }
            if(input[index]== '\n'){++newLines;}
            ++inputRead;
            ++index;
            if(index >= inputSize){return;}
        }
        //(input[index] == '|' && (input[index +1] == '#'))
        if(input[index] == '|'){
            ++inputRead;
            ++index;
            if(index >= inputSize){return;}
            if(input[index] == '#'){
                ++inputRead;
                ++index;
            }
            else if(index >= inputSize){return;}
            else{
                BlockComment(input);
            }
        }
        else{Serr();}

    }
};


#endif //PROJECT_1_COMMENT_H
