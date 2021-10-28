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
string Relation::getName(){
    return name;
}
void Relation::addTuples(Tuple newTuple){
    tuples.emplace(newTuple);
    //bool isEmpty = false;
};

Relation* Relation::select(string valueLookingFor, int column){
    Relation *newRelation = new Relation();
    string sameName = getName();
    newRelation->setName(sameName);
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
    string sameName = getName();
    newRelation->setName(sameName);
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



Relation* Relation::project(vector<int> orderOfColumns){
    Relation* projectRelation= new Relation();
    string sameName = getName();
    projectRelation->setName(sameName);

    //get headers
    //vector<string> keptHeaders(seenIDs.size());
    vector<string> keptHeaders;
    for(unsigned int j = 0; j < orderOfColumns.size(); ++j){
        keptHeaders.push_back(headers.getValue(j)); //header val of that column
        //keptHeaders.insert(keptHeaders.begin()+ i , headers.getValue(i));
    }
    //set headers
    Header selectedHeaders;
    selectedHeaders.setAttributes(keptHeaders);
    projectRelation->setHeader(selectedHeaders);

    //for each tuple, get the string of values from the selected columns
    for(Tuple t : tuples){
        vector<string> keptVariables; ///// i think this is where my issue is
        for(unsigned int i = 0; i < orderOfColumns.size(); i++){//flips through vect of the column numbers we want
            keptVariables.push_back(t.getValue(orderOfColumns.at(i))); //the string that the parameter contains
        }
        Tuple newTuple(keptVariables); //makes new tuple with kept values
        projectRelation->addTuples(newTuple); //adds to new relation
    }

    return projectRelation;
};

Relation* Relation::rename(vector<string> newVarNames){
    Relation* renameRelation= new Relation();
    string sameName = getName();
    renameRelation->setName(sameName);
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