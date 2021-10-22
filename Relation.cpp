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
void Relation::addTuples(Tuple* newTuple){
    try{tuples.emplace(newTuple);}
    catch(exception e){
        cout << e.what();
    }
};

void Relation::toString(){
    cout << "string" ;
}