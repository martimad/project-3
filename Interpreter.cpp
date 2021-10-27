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
        //delete newRelation;
    }
}
void Interpreter::buildFacts(vector<Predicate> predicate){
    //cout << "build facts reached" << endl;
    for(unsigned int i = 0; i < predicate.size(); ++i){
        string keyName;
        keyName = predicate.at(i).getID();
        Tuple newTuple(predicate.at(i).getParamVec());
        database.addTuples(keyName, newTuple);
    }

}

bool Interpreter::build(){
    buildSchemes(datalog.getSchemes());
    buildFacts(datalog.getFacts());

    return true;
}

void Interpreter::evaluateQueries() {
    cout << "eval queries reached" << endl;
    vector<Predicate> queries = datalog.getQueries();

    for(unsigned int i = 0; i < queries.size(); ++i){
        cout << "loop to eval queries" << endl;
        Relation* evaluatedQuery = evaluatePredicate(queries.at(i));
        queriesToString(evaluatedQuery);
        //return relation
    }
}
Relation* Interpreter::evaluatePredicate(Predicate p){
    string RelationName = p.getID();
    Relation* toModify = database.getRelation(RelationName);
    //Relation* toModify = originalRelation;
    vector<Parameter> parVec = p.getParamVec();
    map<string, int> seenIDs;
    // do selects
    for(unsigned int i = 0; i < parVec.size(); ++i){
        if(parVec.at(i).isConstant){
            //then string, call first inst of select
            int column = i; //still need to figure out what this column is
            toModify = toModify->select(parVec.at(i).getString(), column);
        }
        else{
            // is an ID
            if(seenIDs.find(parVec.at(i).getString()) == seenIDs.end()){
                // mark and keep for rename and project, "i" is first time weve seen it
                seenIDs[parVec.at(i).getString()] = i;
            }
            else{
                // if weve seen it before, call second inst of select
                //"i" is now the second time that we have seen it
                int firstColumn;
                firstColumn= seenIDs[parVec.at(i).getString()];
                toModify = toModify->select(firstColumn, i);
            }
            ;

        }
    }

    //do projects, need to fix
    //toModify = toModify->project();

    //do renames
    //toModify = toModify->rename();

    return toModify;

}

void Interpreter::queriesToString(Relation* r) {
    if(r->empty()){
        cout << "No" << endl;
    }
    else{
        cout << "Yes(" << r->numTuples() << ")" <<  endl;
    }
}