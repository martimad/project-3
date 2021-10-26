//
// Created by Madelynn on 10/13/2021.
//

#ifndef PROJECT_2_DATABASE_H
#define PROJECT_2_DATABASE_H

#include "Relation.h"
#include "Tuple.h"
#include "Predicate.h"
#include <iostream>
#include <map>

using namespace std;

class Database {
private:
    map<string, Relation*> databaseMap;
public:
    Database(){};
    ~Database(){};

    void addTuples(string, Tuple*);
    void addToMap(string, Relation*);
    Relation* getRelation(string);

    //void buildSchemes(vector<Predicate>);
    //void buildFacts(vector<Predicate>);

    //void buildQueries();


};


#endif //PROJECT_2_DATABASE_H
