#pragma once
#include <ELLA/stringParser.h>
#include <ELLA/Executor.h>
#include <string>

class ella {

    public:
    const std::string ELLA_VERSION  = "Mark 1";

    void init();

    std::string getUserInput();

    private:
    stringParser SP;
    Executor EX;
    bool introduced = false;
};


