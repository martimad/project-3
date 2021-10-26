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
    bool isEmpty;
public:
    Relation() {
        isEmpty = true;
    };
    ~Relation() = default;
    void setName(string);
    void setHeader(vector<Parameter>);
    void addTuples(Tuple*);
    bool empty();

    //// needs functions select1, select2, project, and rename and tostring
    Relation select(string valueLookingFor, int column);
    //One version of select finds all the tuples that have a constant value in a certain column
    //need to know what column to check for and what value should be in the column

    Relation select(vector<int> columns); //size should be >2
    //Another version of select finds all the tuples that have the same value in two different columns
    //(it doesn't matter what the value is, as long as both columns have the same value).

    Relation project();
    //We need to have a list of what columns we should keep
    //Columns are indexed by number, so we need a vector of ints to list what columns we should keep

    Relation rename();
    //We need to know what scheme attributes are changing and what they are changing to
    //give an entire header as input

    void toString();

};


#endif //PROJECT_2_RELATION_H
