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

void Interpreter::evaluateQueries() {
    vector<Predicate> queries = datalog.getQueries();
    for(unsigned int i = 0; i < queries.size(); ++i){
        Relation evaluatedQuery = evaluatePredicate(queries.at(i));
        queriesToString(evaluatedQuery);
        //return relation
    }
}
Relation Interpreter::evaluatePredicate(Predicate p){
    string RelationName = p.getID();
    Relation* originalRelation = database.getRelation(RelationName);

    Relation toModify = *originalRelation;
    vector<Parameter> parVec = p.getParamVec();
    // do selects
    for(unsigned int i = 0; i < parVec.size(); ++i){
        if(parVec.at(i).isConstant){
            //then string, call first inst of select
            int column; //still need to figure out what this column is
            toModify.select(parVec.at(i).getString(), column);
        }
        else{
            // is an ID
            // if weve seen it before, call second inst of select
            vector<int> ints; // need to figure out what this vec is
            toModify = toModify.select(ints);
            // else mark and keep for rename and project
        }
    }

    //do projects, need to fix
    toModify = toModify.project();

    //do renames
    toModify = toModify.rename();

    return toModify;

}

void Interpreter::queriesToString(Relation& r) {
    r.toString();
    cout << endl;
}