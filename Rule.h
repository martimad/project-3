//
// Created by Madelynn on 9/15/2021.
//

#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H
#include "Predicate.h"


class Rule {
private:
Predicate headPredicate;
vector<Predicate> bodyPredicates;
public:
    Rule(Predicate headPred, vector<Predicate> bodPred) : headPredicate(headPred), bodyPredicates(bodPred){
        //headPredicate = headPred;
    };
    string toString(){
        stringstream ss;
        ss << headPredicate.toString() << " :- " ;
        for(unsigned int i = 0; i < bodyPredicates.size(); ++ i){
            ss << bodyPredicates.at(i).toString() << ",";
        }
        string returnString = ss.str();
        returnString.pop_back();
        return returnString;
    }
};


#endif //PROJECT_2_RULE_H
