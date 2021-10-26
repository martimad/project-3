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
    try{tuples.emplace(newTuple);
    bool isEmpty = false;}
    catch(exception e){
        cout << e.what();
    }
};

Relation Relation::select(string valueLookingFor, int column){
    Relation selectRelation;
    return selectRelation;
};
Relation Relation::select(vector<int> columns){
    Relation selectRelation;
    return selectRelation;
};



Relation Relation::project(){
    Relation projectRelation;
    return projectRelation;
};

Relation Relation::rename(){
    Relation renameRelation;
    return renameRelation;
};

bool Relation::empty(){
    if(tuples.size() == 0){
        isEmpty = true;
    }
    else { isEmpty = false;}
    return isEmpty;
}

void Relation::toString(){
    cout << name ;
}