//
// Created by Madelynn on 9/15/2021.
//

#include "DatalogProgram.h"
using namespace std;

void DatalogProgram::addToScheme(Predicate schemePredicate){
    schemePredicates.push_back(schemePredicate);
};
void DatalogProgram::addToFact(Predicate predicate){
    factPredicates.push_back(predicate);
};
void DatalogProgram::addToQueries(Predicate predicate){
    queriesPredicates.push_back(predicate);
};
void DatalogProgram::addToRule(Rule rulesList){
    rulePredicates.push_back(rulesList);
};
void DatalogProgram::addToSet(const string stringToAdd){
    domains.insert(stringToAdd);
};
void DatalogProgram::toString(){
    cout << "Schemes(" << schemePredicates.size() << "):" << endl;
    //iterate through schemes
    for(unsigned int i = 0; i < schemePredicates.size(); ++ i){
        cout << "  " << schemePredicates.at(i).toString() << endl;
    }

    cout << "Facts(" << factPredicates.size() << "):" << endl;
    //iterate through facts
    for(unsigned int i = 0; i < factPredicates.size(); ++ i){
        cout << "  " <<factPredicates.at(i).toString()  << "." << endl;
    }

    cout << "Rules(" << rulePredicates.size() << "):" << endl;
    //iterate through rules
    for(unsigned int i = 0; i < rulePredicates.size(); ++ i){
        cout << "  " << rulePredicates.at(i).toString() << "." << endl;
    }

    cout << "Queries(" << queriesPredicates.size() << "):" << endl;
    //iterate through queries
    for(unsigned int i = 0; i < queriesPredicates.size(); ++ i){
        cout << "  " << queriesPredicates.at(i).toString() << "?" << endl;
    }

    cout << "Domain(" << domains.size() << "):" << endl;
    //iterate through domain
    auto it = domains.begin();
    while(it != domains.end()){
        cout << "  " << *it << endl;
        ++it;
    }
}

vector<Predicate> DatalogProgram::getSchemes() {
    return schemePredicates;
}
vector<Predicate> DatalogProgram::getFacts(){
    return factPredicates;
}
vector<Predicate> DatalogProgram::getQueries(){
    return queriesPredicates;
};