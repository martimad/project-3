
#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Token.h"
using namespace std;
int main(int argc, char** argv) {
    if (argc < 2){
        cerr << "please provide input values" << endl;
        return 1;
    }
    ifstream in(argv[1]);
    if(!in){
        cerr << "input stream not working" << endl;
        return 2;
    }
//    string line;
//    getline(in, line);
//    cout << line;
    stringstream ss;
    ss << in.rdbuf();
    string fileContentToPass = ss.str();
    Lexer* lexer = new Lexer();
    vector <Token*> tokensFromLexer;
    Parser* parser = new Parser();

    lexer->Run(fileContentToPass);
    tokensFromLexer = lexer->returnVector();
    //lexer->toString();

    ////start parser
    try{
        parser->Run(tokensFromLexer);
    }catch(Token* thrownToken) {
        //string errorString = "Expected " + matchType + " but got " + thrownToken->tokenType();
        cout << "Failure!" << endl << thrownToken->toString() << endl;
        return 0;
    }catch(string errorStatement) {
        cout << "Failure!" << endl << errorStatement << endl;
        return 0;
    }
    parser->toString();

    delete lexer;
    delete parser;

    return 0;
}