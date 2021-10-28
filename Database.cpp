//
// Created by Madelynn on 10/13/2021.
//

#include "Database.h"
#include <iostream>

void Database::addTuples(string keyName, Tuple tuple1) {
    databaseMap[keyName]->addTuples(tuple1);
}

void Database::addToMap(string keyName, Relation* newRelation){
    databaseMap.insert(pair{keyName, newRelation});
}
Relation* Database::getRelation(string keyName){
    Relation* relationToReturn = databaseMap.find(keyName)->second;
    return relationToReturn;
};