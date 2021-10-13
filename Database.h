//
// Created by Madelynn on 10/13/2021.
//

#ifndef PROJECT_2_DATABASE_H
#define PROJECT_2_DATABASE_H

#include "Relation.h"
#include "Tuple.h"
#include <iostream>
#include <map>

using namespace std;

class Database {
private:
    map<string, Relation*> databaseMap;
public:
    Database();
    ~Database();


};


#endif //PROJECT_2_DATABASE_H
