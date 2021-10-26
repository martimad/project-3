//
// Created by Madelynn on 9/15/2021.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H
#include "Parameter.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//used for facts schemes and queries
class Predicate {
private:
    string initialID;
    vector<Parameter> parameters;
public:
    Predicate(string initialIDPassed, vector<Parameter> parametersPassed ) : parameters(parametersPassed){
        this->initialID = initialIDPassed;
    }
    string getID(){
        return initialID;
    };
    vector<Parameter> getParamVec(){
        return parameters;
    }

    string toString(){
        stringstream ss;
        ss << initialID << "(";
        for(unsigned int i = 0; i < parameters.size(); ++i){
            ss << parameters[i].getString() << "," ;
        }
        string returnString = ss.str();
        returnString.pop_back();
        returnString += ")";
        return returnString;
    }


};


#endif //PROJECT_2_PREDICATE_H
