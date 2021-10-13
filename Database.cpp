//
// Created by Madelynn on 10/13/2021.
//

#include "Database.h"
#include <iostream>

void Database::buildSchemes(vector<Predicate> predicate) {
    for(unsigned int i = 0; i < predicate.size(); i++){
        Relation* newRelation = new Relation();
        // Relation newRelation;
        string keyName;
        keyName = predicate.at(i).getID();
        newRelation->setName(keyName);
        newRelation->setHeader(predicate.at(i).getParamVec());
        databaseMap.insert(pair{keyName, newRelation});
        delete newRelation;
    }

}