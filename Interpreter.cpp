//
// Created by Madelynn on 10/22/2021.
//

#include "Interpreter.h"
void Interpreter::buildSchemes(vector<Predicate> predicate) {
    for (unsigned int i = 0; i < predicate.size(); i++) {
        Relation *newRelation = new Relation();
        // Relation newRelation;
        string keyName;
        keyName = predicate.at(i).getID();
        newRelation->setName(keyName);
        newRelation->setHeader(predicate.at(i).getParamVec());
        database.addToMap(keyName, newRelation);
        delete newRelation;
    }
}
void Interpreter::buildFacts(vector<Predicate> predicate){
    //cout << "build facts reached" << endl;
    for(unsigned int i = 0; i < predicate.size(); ++i){
        string keyName;
        keyName = predicate.at(i).getID();
        Tuple* newTuple = new Tuple(predicate.at(i).getParamVec());
        database.addTuples(keyName, newTuple);
    }

}

bool Interpreter::build(){
    buildSchemes(datalog.getSchemes());
    buildFacts(datalog.getFacts());

    return true;
}