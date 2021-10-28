//
// Created by Madelynn on 10/13/2021.
//

#ifndef PROJECT_2_HEADER_H
#define PROJECT_2_HEADER_H
#include <iostream>
#include <vector>
#include "Parameter.h"
#include <algorithm>
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
    void setAttributes(vector<string> string){
        for(unsigned int i = 0 ; i < string.size(); i++){
            headers.push_back(string.at(i));
        }
    }
    void changeValue(string newName, int firstOccurance){
        string oldVal = headers.at(firstOccurance);
        std::replace(headers.begin(), headers.end(), oldVal, newName);
    }
    string getValue(int index){
        return headers.at(index);
    }
    int getSize(){
        return headers.size();
    }

};
#endif //PROJECT_2_HEADER_H
