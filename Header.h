//
// Created by Madelynn on 10/13/2021.
//

#ifndef PROJECT_2_HEADER_H
#define PROJECT_2_HEADER_H
#include <iostream>
#include <vector>
#include "Parameter.h"
using namespace std;

class Header{
private:
    vector<string> headers;
public:
    Header() = default;
    ~Header() = default;
    void setAttributes(vector<Parameter> parameter){
        for(unsigned int i = 0 ; i < parameter.size(); i++){
            headers.push_back(parameter.at(i).getString());
        }
    }

};
#endif //PROJECT_2_HEADER_H
