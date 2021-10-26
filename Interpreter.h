//
// Created by Madelynn on 10/22/2021.
//

#ifndef PROJECT_2_INTERPRETER_H
#define PROJECT_2_INTERPRETER_H
#include "Relation.h"
#include "Tuple.h"
#include "Predicate.h"
#include "DatalogProgram.h"
#include "Database.h"
#include <iostream>


class Interpreter {
private:
    DatalogProgram datalog;
    Database database;
public:
    Interpreter(DatalogProgram datalogFromParser) : datalog(datalogFromParser){};
    bool build();
    void buildSchemes(vector<Predicate>);
    void buildFacts(vector<Predicate>);
    Relation evaluatePredicate(Predicate p);
    void evaluateQueries();
    void queriesToString(Relation& r);
};


#endif //PROJECT_2_INTERPRETER_H
