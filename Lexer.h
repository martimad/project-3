#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"
using namespace std;

class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;

    void CreateAutomata();
public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    void toString();
    vector<Token*> returnVector();


};

#endif // LEXER_H

