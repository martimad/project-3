//
// Created by Madelynn on 9/15/2021.
//

#include "Parser.h"
#include <iostream>

using namespace std;

void Parser::Run(vector<Token*> tokensPassed){
    tokens = tokensPassed;
    tokenIndex = 0;
    datalogProgram();
}

void Parser::toString(){
    cout << "Success!" << endl;
    data.toString();
}

string Parser::match(string matchType){
    if (tokens.at(tokenIndex)->tokenType() == matchType){
        ++tokenIndex;
        return tokens.at(tokenIndex -1)->returnValue();
    }
    else {
        auto s = to_string(tokens.at(tokenIndex)->lineNumVal());
        string errorString = "  (" + tokens.at(tokenIndex)->tokenType() + ",\"" + tokens.at(tokenIndex)->returnValue() + "\"," + s + ")";
        throw errorString;
    }
}


void Parser::datalogProgram() {
    //    datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    match("SCHEMES");
    match("COLON");
    scheme();
    //cout << "scheme finished" << endl;
    if(tokens.at(tokenIndex)->tokenType() =="ID"){
        //cout << "calling schemeList" << endl;
        schemeList();
    }

    //cout << "function returned, ready to start facts" << endl;
    match("FACTS");
    match("COLON");
    if(tokens.at(tokenIndex)->tokenType() =="ID") {
        //cout << "calling factsList" << endl;
        factList();
    }

    //cout << "function returned, ready to start Rules" << endl;
    match("RULES");
    match("COLON");
    if(tokens.at(tokenIndex)->tokenType() =="ID") {
        //cout << "calling ruleList" << endl;
        ruleList();
    }

    //cout << "function returned, ready to start Queries" << endl;
    match("QUERIES");
    match("COLON");
    if(tokens.at(tokenIndex)->tokenType() =="ID") {
       //cout << "calling query" << endl;
        query();
    }
    if(tokens.at(tokenIndex)->tokenType() =="ID") {
        //cout << "calling queryList" << endl;
        queryList();
    }
    //cout << "this point reached" << endl;
    if(tokens.at(tokenIndex)->tokenType()== "EOF"){
        ++tokenIndex;
    }
    //cout <<  "syntax checking completed" << endl;

}

//lists, scheme, fact, rule and query
void Parser::schemeList() {
    //    schemeList	->	scheme schemeList | lambda
    if(tokens.at(tokenIndex)->tokenType() == "ID"){
        scheme();
        if(tokens.at(tokenIndex)->tokenType() =="ID"){
            //cout << "calling schemeList again";
            schemeList();
        }
    }
    else if (tokens.at(tokenIndex)->tokenType() =="FACTS"){
        return;
    }
    else {
        string error = "Facts not the next token after schemeList. Thrown from SchemeList";
        throw error;
    }
}
void Parser::factList(){
    //     factList	->	fact factList | lambda
    //cout << "factList called" << endl;
    if(tokens.at(tokenIndex)->tokenType() == "ID"){
        fact();
        if(tokens.at(tokenIndex)->tokenType() =="ID"){
            //cout << "calling factList again" << endl;
            factList();
        }
    }
    else if (tokens.at(tokenIndex)->tokenType() =="RULES"){
        return;
    }
    else {
        string error = "Rules not the next token after factList. Thrown from factList" ;
        throw error;
    }

}
void Parser::ruleList(){
    //  ruleList	->	rule ruleList | lambda
    //cout << "ruleList called" << endl;
    if(tokens.at(tokenIndex)->tokenType() =="ID"){
        rule();
        if(tokens.at(tokenIndex)->tokenType() =="ID"){
            //cout << "calling ruleList again" << endl;
            ruleList();
        }
    }
    else if (tokens.at(tokenIndex)->tokenType() =="QUERIES"){
        return;
    }
    else {
        string error =  "Queries not the next token after ruleList. Thrown from ruleList" ;
        throw error;
    }

}
void Parser::queryList(){
    //queryList	->	query queryList | lambda
    //cout << "queryList called" << endl;
    if(tokens.at(tokenIndex)->tokenType() =="ID"){
        query();
        if(tokens.at(tokenIndex)->tokenType() =="ID"){
            //cout << "calling queryList again" << endl;
            queryList();
        }
    }
}

void Parser::scheme(){
    // scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "scheme called" << endl;
    string schemeID;
    vector<Parameter> schemeParameters;

    schemeID = match( "ID");
    match("LEFT_PAREN");
    schemeParameters.push_back(match("ID"));
    idList(schemeParameters);
    match("RIGHT_PAREN");
    Predicate schemePredicate(schemeID, schemeParameters);
    data.addToScheme(schemePredicate);
}

void Parser::fact (){
// fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    vector<Parameter> factParameters;
    string factID;

    //cout << "fact called" << endl;

    factID = match( "ID");
    match("LEFT_PAREN");
    factParameters.push_back(Parameter(match("STRING")));
    stringList(factParameters);
    //cout << "string list returned to fact" << endl;
    match("RIGHT_PAREN");
    match("PERIOD");

    for(unsigned int i = 0; i < factParameters.size(); ++i){
        string setItem = factParameters.at(i).getString();
        data.addToSet(setItem);
        //cout << setItem;
    }
    Predicate factPredicate(factID, factParameters);
    data.addToFact(factPredicate);
}

void Parser::rule(){
//    rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    //cout << "rule was called" << endl;

    Predicate headPred = headPredicate();
    //cout << "head predicate returned" << endl;

    match("COLON_DASH");
    vector<Predicate> rulePreds;
    Predicate firstRulePred = ParsePredicate();
    //cout << "first rule pred returned" << endl;
    rulePreds.push_back(firstRulePred);
    predicateList(rulePreds);
    match("PERIOD");
    Rule rulePredicates(headPred, rulePreds);
    data.addToRule(rulePredicates);
}
void Parser::query(){
//     query->   predicate Q_MARK
    //cout << "query called" << endl;
    Predicate queryPredicate(ParsePredicate());
    match("Q_MARK");
    //cout << "queries finished" << endl;
    data.addToQueries(queryPredicate);

}


////predicate functions
Predicate Parser::headPredicate(){
//headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "headPredicate was called" << endl;
    string headPredID;
    vector<Parameter> headPredParam;

    headPredID = match("ID");
    match("LEFT_PAREN");
    headPredParam.push_back(match("ID"));
    idList(headPredParam);
    match("RIGHT_PAREN");
    Predicate headPred(headPredID, headPredParam);
    return headPred;

}
Predicate Parser::ParsePredicate(){
//            predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    //cout << "predicate was called" << endl;
    vector<Parameter> vecParameters;
    string predID = match("ID");
    match("LEFT_PAREN");
    parameter(vecParameters);
    //cout << "parameter returned" << endl;
    parameterList(vecParameters);
    match("RIGHT_PAREN");
    Predicate pred(predID, vecParameters);
    return pred;
}
void Parser::predicateList(vector<Predicate>& passedVec){
//            predicateList	->	COMMA predicate predicateList | lambda
    //cout << "predicate list called" << endl;
    if(tokens.at(tokenIndex)->tokenType() == "COMMA") {
        match("COMMA");
        passedVec.push_back(ParsePredicate());
        predicateList(passedVec);
    }
    else{return;}

}
void Parser::parameterList(vector<Parameter>& passedVec){
//            parameterList	-> 	COMMA parameter parameterList | lambda
    //cout << "parameter list was called" << endl;
    if(tokens.at(tokenIndex)->tokenType() == "COMMA") {
        match("COMMA");
        parameter(passedVec);
        parameterList(passedVec);
    }
    else{return;}
}
void Parser::stringList(vector<Parameter>& parameterVec){
//            stringList	-> 	COMMA STRING stringList | lambda

    if(tokens.at(tokenIndex)->tokenType() == "COMMA") {
        match("COMMA");
        parameterVec.push_back(Parameter(match("STRING")));
        stringList(parameterVec);
    }
    else { return; }
}
void Parser::idList(vector<Parameter>& parameterVec){
//            idList  	-> 	COMMA ID idList | lambda
    //cout << "Id list was called" << endl;
    if(tokens.at(tokenIndex)->tokenType() == "COMMA") {
        match("COMMA");
        parameterVec.push_back(Parameter(match("ID")));
        idList(parameterVec);
    }
    else { return; }
}
void Parser::parameter(vector<Parameter>& passedVec){
//            parameter	->	STRING | ID
    //cout << "parameter was called" << endl;
    if(tokens.at(tokenIndex)->tokenType() == "STRING") {
        passedVec.push_back(Parameter(match("STRING")));
    }
    else{ passedVec.push_back(Parameter(match("ID"))); }
}


DatalogProgram Parser::getDatalog() {
    return data;
}
