#include <iostream>
#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "MatcherAutomaton.h"
#include "Comment.h"
#include "ID.h"
#include "String.h"


using namespace std;
Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new MatcherAutomaton(",", TokenType::COMMA));
    automata.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
    automata.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
    automata.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
    automata.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
    //automata.push_back(new MatcherAutomaton(":", TokenType::COLON));
    //automata.push_back(new MatcherAutomaton(":-", TokenType::COLON-DASH));
    automata.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
    automata.push_back(new MatcherAutomaton("+", TokenType::ADD));
    automata.push_back(new MatcherAutomaton("Schemes", TokenType::SCHEMES));
    automata.push_back(new MatcherAutomaton("Facts", TokenType::FACTS));
    automata.push_back(new MatcherAutomaton("Rules", TokenType::RULES));
    automata.push_back(new MatcherAutomaton("Queries", TokenType::QUERIES));
    automata.push_back(new ID());
    automata.push_back(new String());
    automata.push_back(new Comment());
    //    EOF_TYPE
}

void Lexer::Run(string& input) {
    unsigned int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        unsigned int maxRead = 0;
        Automaton *maxAutomaton = automata[0];


        while(isspace(input[0])){
            if(input.substr(0,1) == "\n"){++lineNumber;}
            input = input.substr(1);
            if(input.size() == 0){break;}
        }

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        //unsigned int inputRead = 0;
        if(input.size() == 0){break;}
        for (unsigned int i = 0; i < automata.size(); ++i) {// each automaton in automata)
            unsigned int inputRead = automata[i]->Start(input);

            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i]; //set maxAutomaton to automaton
            }
        }

        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            if(maxRead == input.size()){
                tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0,maxRead), lineNumber));
                lineNumber += maxAutomaton->NewLinesRead();
            }
            else {
                Token *newToken = maxAutomaton->CreateToken(input.substr(0, maxRead),
                                                            lineNumber);//needed string and line numbers)
                lineNumber += maxAutomaton->NewLinesRead(); //increment lineNumber by maxAutomaton.NewLinesRead()
                if(newToken->tokenType() != "COMMENT"){
                    tokens.push_back(newToken);//add newToken to collection of all tokens;
                }
            }
        }

        // No automaton accepted input, create single character undefined token
        else {
            maxRead = 1;
            tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0,1), lineNumber)); //add newToken to collection of all tokens
        }
        input = input.substr(maxRead);//from max read to end

   }
    tokens.push_back(new Token(TokenType::EOF_TYPE, "", lineNumber)); //end of file token
}

vector<Token*> Lexer::returnVector() {
    return tokens;
}

void Lexer::toString(){
    for(unsigned int i = 0; i < tokens.size(); ++i){
        cout << tokens[i]->toString() << endl;
    }
    cout << "Total Tokens = " << tokens.size();

}
