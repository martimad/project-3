//
// Created by Madelynn on 10/13/2021.
//

#include "Database.h"
#include <iostream>

//void Database::buildSchemes(vector<Predicate> predicate) {
//    for (unsigned int i = 0; i < predicate.size(); i++) {
//        Relation *newRelation = new Relation();
//        // Relation newRelation;
//        string keyName;
//        keyName = predicate.at(i).getID();
//        newRelation->setName(keyName);
//        newRelation->setHeader(predicate.at(i).getParamVec());
//        databaseMap.insert(pair{keyName, newRelation});
//        delete newRelation;
//    }
//}
//void Database::buildFacts(vector<Predicate> predicate){
//    //cout << "build facts reached" << endl;
//    for(unsigned int i = 0; i < predicate.size(); ++i){
//        string keyName;
//        keyName = predicate.at(i).getID();
//        Tuple* newTuple = new Tuple(predicate.at(i).getParamVec());
//        databaseMap[keyName]->addTuples(newTuple);
//    }
//    //cout << "build facts finished" << endl;
//}

void Database::addTuples(string keyName, Tuple* tuple1) {
    databaseMap[keyName]->addTuples(tuple1);
}

void Database::addToMap(string keyName, Relation* newRelation){
    databaseMap.insert(pair{keyName, newRelation});
}