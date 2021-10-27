//
// Created by Madelynn on 10/13/2021.
//

#ifndef PROJECT_2_TUPLE_H
#define PROJECT_2_TUPLE_H
#include <iostream>
#include <vector>

using namespace std;
class Tuple{
private:
    vector<string> listOfAttributes;
public:
    Tuple() = default;
    Tuple(vector<Parameter> parameter){
        for(unsigned int i = 0 ; i < parameter.size(); ++i){
            listOfAttributes.push_back(parameter.at(i).getString());
        }
    }
    ~Tuple() = default;
    string getValue(int index){
        return listOfAttributes.at(index);
    }

    bool operator< (const Tuple &rhs) const {
        return listOfAttributes < rhs.listOfAttributes;
    }
};
#endif //PROJECT_2_TUPLE_H
