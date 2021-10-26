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
void Relation::setHeader(Header newHeader){
    headers = newHeader;
}
Header Relation::getHeader(){
    return headers;
};
void Relation::addTuples(Tuple* newTuple){
    try{tuples.emplace(newTuple);
    bool isEmpty = false;}
    catch(exception e){
        cout << e.what();
    }
};

Relation* Relation::select(string valueLookingFor, int column){
    Relation* newRelation = new Relation();
    Header sameHeaders = getHeader();
    newRelation->setHeader(sameHeaders);

    return newRelation;
};
Relation* Relation::select(vector<int> columns){
    Relation* newRelation = new Relation();
    return newRelation;
};



Relation* Relation::project(){
    Relation* projectRelation= new Relation();
    return projectRelation;
};

Relation* Relation::rename(){
    Relation* renameRelation= new Relation();
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