//
// Created by Madelynn on 10/13/2021.
//

#ifndef PROJECT_2_RELATION_H
#define PROJECT_2_RELATION_H
#include <iostream>
#include <set>
#include "Header.h"
#include "Tuple.h"
using namespace std;

class Relation {
private:
    string name;
    Header headers;
    set<Tuple*> tuples;
public:
    Relation() {

    };
    ~Relation() = default;
    void setName(string);
    void setHeader(vector<Parameter>);
    void addTuples(Tuple*);

    //// needs functions select1, select2, project, and rename and tostring
    //Relation select();
    void select();
    void project();
    void rename();

    void toString();

};


#endif //PROJECT_2_RELATION_H
