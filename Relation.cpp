//
// Created by Madelynn on 10/13/2021.
//

#include "Relation.h"
//// needs functions select1, select2, project, and rename

void Relation::setName(string name){
    this->name = name;
};
void Relation::setHeader(vector<Parameter> parameters){
    this->headers.setAttributes(parameters);
};
//void Relation::setTuples(set<Tuple> tuples){
//    for(int i = 0; i < tuples.size() ; ++i){
//        this->tuples.at(i) = tuples.at(i);
//    }
//};