#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EOF_TYPE,
};

class Token
{
private:
    TokenType type;
    string description;
    int lineNum;


public:
    Token(TokenType type, std::string description, int line);
    string tokenToString(TokenType);
    string toString();
    string tokenType(){
        return tokenToString(type);
    }
    string returnValue();
    int lineNumVal();
};

#endif // TOKEN_H

