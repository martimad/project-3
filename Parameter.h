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
    Parameter(string parameterPassed){
        this->parameter = parameterPassed;
    };
    string getString(){
        return parameter;
    };

};


#endif //PROJECT_2_PARAMETER_H
