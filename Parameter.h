//
// Created by Madelynn on 9/15/2021.
//

#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H
#include <iostream>
using namespace std;

class Parameter {
private:
    string parameter;
////needed to string
public:
    Parameter(string parameterPassed, string type){
        this->parameter = parameterPassed;
        if(type == "string"){
            isConstant = true;
        }
        else isConstant = false;
    };
    string getString(){
        return parameter;
    };
    bool isConstant;

};


#endif //PROJECT_2_PARAMETER_H
