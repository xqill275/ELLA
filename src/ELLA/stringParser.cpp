#include <ELLA/stringParser.h>
#include <algorithm> // for std::transform

stringParser::stringParser() {}

void stringParser::init(const std::string& userInput) {
    initDictionary();
    tokenize(userInput);
}

std::vector<stringParser::Token> stringParser::getTokens() const {
    return tokens;
}

void stringParser::initDictionary() {
    using TT = TokenType;

    dictionary = {
        {"hello", TT::GREETING},
        {"hi", TT::GREETING},
        {"please", TT::GREETING},
        {"make", TT::COMMAND},
        {"create", TT::COMMAND},
        {"remove", TT::COMMAND},
        {"delete", TT::COMMAND},
        {"called", TT::COMMAND},
        {"named", TT::COMMAND},
        {"a", TT::NUMBER},
        {"an", TT::NUMBER},
        {"folder", TT::FILE_TYPE},
        {"file", TT::FILE_TYPE},
        {"project", TT::FILE_TYPE}
    };
}

void stringParser::tokenize(const std::string& input) {
    tokens.clear();
    std::istringstream stream(input);
    std::string word;

    bool expectName = false;

    while (stream >> word) {
        Token token;
        token.word = word;

        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            token.type = it->second;
            tokens.push_back(token);

            // Expect next token to be a name if this is a FILE_TYPE
            expectName = (token.word == "named" || token.word == "called");
        } else {
            if (expectName) {
                token.type = NAME;
                expectName = false;
            } else {
                token.type = UNKNOWN;
            }
            tokens.push_back(token);
        }
    }
}
