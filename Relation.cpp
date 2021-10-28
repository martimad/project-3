//
// Created by Madelynn on 10/13/2021.
//

#include "Relation.h"
//// needs functions select1, select2, project, and rename

void Relation::setName(string name){
    this->name = name;
};
void Relation::setHeader(vector<Parameter> parameters){
    this->headers.setAttributes(parameters);
};
void Relation::setHeader(Header newHeader){
    headers = newHeader;
}
void Relation::setHeader(vector<string> strings){
    this->headers.setAttributes(strings);
}
Header Relation::getHeader(){
    return headers;
};
void Relation::addTuples(Tuple newTuple){
    tuples.emplace(newTuple);
    //bool isEmpty = false;
};

Relation* Relation::select(string valueLookingFor, int column){
    Relation *newRelation = new Relation();
    Header sameHeaders = getHeader();
    newRelation->setHeader(sameHeaders);
    for(Tuple t : tuples){
        if(t.getValue(column) == valueLookingFor){
            newRelation->addTuples(t);
            newRelation->isEmpty = false;
        }
    }
    return newRelation;
};

Relation* Relation::select(int firstColumn, int secondColumn){
    Relation* newRelation = new Relation();
    Header sameHeaders = getHeader();
    newRelation->setHeader(sameHeaders);
    for(Tuple t : tuples){
        if(t.getValue(firstColumn) == t.getValue(secondColumn)){
            newRelation->addTuples(t);
            isEmpty = false;
        }
    }
    return newRelation;
};



Relation* Relation::project(map<string, int> seenIDs){
    Relation* projectRelation= new Relation();

    //get headers
    vector<string> keptHeaders;
    vector<int> columnsToKeep;
    for(auto it = seenIDs.begin(); it != seenIDs.end(); it++){
        int i = it->second;//the column num that is is in
        keptHeaders.push_back(headers.getValue(i)); //header val of that column
        columnsToKeep.push_back(i); //indexes of columns that we want it to keep
    }
    //set headers
    Header selectedHeaders;
    selectedHeaders.setAttributes(keptHeaders);
    projectRelation->setHeader(selectedHeaders);

    //for each tuple, get the string of values from the selected columns
    for(Tuple t : tuples){
        vector<string> keptVariables; ///// i think this is where my issue is
        for(unsigned int i = 0; i < columnsToKeep.size(); i++){ //flips through vect of the column numbers we want
            keptVariables.push_back(t.getValue(columnsToKeep.at(i))); //the string that the parameter contains
        }
        Tuple newTuple(keptVariables); //makes new tuple with kept values
        projectRelation->addTuples(newTuple); //adds to new relation
    }

    return projectRelation;
};

Relation* Relation::rename(vector<string> newVarNames){
    Relation* renameRelation= new Relation();
    renameRelation->setHeader(newVarNames);
    for(Tuple t : tuples){
        renameRelation->addTuples(t);
    }
    return renameRelation;
}

bool Relation::empty(){
    if(tuples.size() == 0){
        isEmpty = true;
    }
    else { isEmpty = false;}
    return isEmpty;
}

string Relation::toString(){
    stringstream ss;
    if(tuples.empty()){
        string fakeString = "only one relation";
        return fakeString;
    }
    for(Tuple t : tuples){
        if(headers.getSize() >= 1) {
            stringstream small;
            small << "  ";
            for (int i = 0; i < headers.getSize(); ++i) {
                small << headers.getValue(i) << "=" << t.getValue(i) << ", ";
            }
            string pieceString = small.str();
            string commaOff = pieceString.substr(0, pieceString.size() - 2);
            ss << commaOff << endl;
        }
    }
    string returnString = ss.str();
    return returnString;
}