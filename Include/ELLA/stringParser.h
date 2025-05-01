#pragma once

#include <vector>
#include <sstream>
#include <unordered_map>

class stringParser {


    public:
    enum TokenType {
        GREETING, // hello
        COMMAND, // make
        NUMBER, // a
        FILE_TYPE, // folder
        NAME, // example_folder
        UNKNOWN 
    };

    struct Token {
        std::string word;
        TokenType type;
    };

    stringParser();

    void init(const std::string& userInput);
    std::vector<Token> getTokens() const;


    private:
    std::vector<Token> tokens;
    std::unordered_map<std::string, TokenType> dictionary;

    void tokenize(const std::string& input);
    void initDictionary();
    
};

// exsample command
// "please make me a folder called something" ->
// please = GREETING
// make = COMMAND
// a = NUMBER
// folder = TYPE
// called = COMMAND
// something = NAME