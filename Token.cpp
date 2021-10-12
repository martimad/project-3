#include "Token.h"
#include <sstream>
using namespace std;
Token::Token(TokenType type, string description, int line) {
    this->type = type;
    this->description = description;
    lineNum = line;
}
string Token::tokenToString(TokenType type){
        switch (type) {
            case TokenType :: COLON : return "COLON";
            case TokenType :: COLON_DASH: return "COLON_DASH";
            case TokenType :: PERIOD : return "PERIOD";
            case TokenType :: COMMA : return "COMMA";
            case TokenType :: Q_MARK : return "Q_MARK";
            case TokenType :: LEFT_PAREN : return "LEFT_PAREN";
            case TokenType :: RIGHT_PAREN : return "RIGHT_PAREN";
            case TokenType :: MULTIPLY : return "MULTIPLY";
            case TokenType :: ADD : return "ADD";
            case TokenType :: SCHEMES : return "SCHEMES";
            case TokenType :: FACTS : return "FACTS";
            case TokenType :: RULES : return "RULES";
            case TokenType :: QUERIES : return "QUERIES";
            case TokenType :: ID : return "ID";
            case TokenType :: STRING: return "STRING";
            case TokenType :: COMMENT : return "COMMENT";
            case TokenType :: UNDEFINED : return "UNDEFINED";
            case TokenType :: EOF_TYPE : return "EOF";
        }
        return "error";
    }


string Token::toString() {
    stringstream ss;
    ss << "(" << tokenToString(type) << ",\"" << description << "\"," << lineNum << ")";
    return ss.str();
}

string Token::returnValue(){
    return description;
}

int Token::lineNumVal(){
    return lineNum;
}