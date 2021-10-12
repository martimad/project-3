//
// Created by Madelynn on 9/15/2021.
//
#pragma once
#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H
#include "Token.h"
#include "DatalogProgram.h"
#include <vector>

using namespace std;

// this class checks if the tokens fit the grammar
class Parser {
private:
    vector<Token*> tokens;
    int tokenIndex;
    DatalogProgram data;

public:
    Parser() = default;
    ~Parser() = default;
    void Run(vector<Token*> tokensPassed);
    void toString();
    string match(string);

    ////non terminal functions
    void datalogProgram();
    //scheme functions
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    void scheme();
    void fact ();
    //rule functions
    void rule();
    void query();
    //predicate functions
    Predicate headPredicate();
    Predicate ParsePredicate();
    void predicateList(vector<Predicate>&);
    void parameterList(vector<Parameter>&);
    void stringList(vector<Parameter>&);
    void idList(vector<Parameter>&);
    void parameter(vector<Parameter>&);



};


#endif //PROJECT_2_PARSER_H
