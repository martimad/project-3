//
// Created by Madelynn on 9/15/2021.
//

#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H
#include <vector>
#include <set>
#include "Predicate.h"
#include "Rule.h"

using namespace std;

class DatalogProgram {
private:
    vector<Predicate> schemePredicates;
    vector<Predicate> factPredicates;
    vector<Predicate> queriesPredicates;
    vector<Rule> rulePredicates;
    set<string> domains;
    //domain, all the parameters in the facts sets

public:
    DatalogProgram() = default;
    void addToScheme(Predicate);
    void addToFact(Predicate);
    void addToQueries(Predicate);
    void addToRule(Rule);
    void addToSet(const string);
    void toString();

    vector<Predicate> getSchemes();
};


#endif //PROJECT_2_DATALOGPROGRAM_H
