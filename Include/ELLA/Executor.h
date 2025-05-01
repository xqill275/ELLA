#pragma once

#include <string>
#include <vector>
#include <ELLA/stringParser.h>

struct Intent {
    std::string action;
    std::string type;
    std::string name;
};

class Executor {
public:
    Executor();
    Intent parseIntent(const std::vector<stringParser::Token>& tokens);
    void executeIntent(const Intent& intent);
};