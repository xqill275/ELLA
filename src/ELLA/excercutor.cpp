#include <iostream>
#include <filesystem>
#include <ELLA/Executor.h>

namespace fs = std::filesystem;

Executor::Executor() {}

Intent Executor::parseIntent(const std::vector<stringParser::Token>& tokens) {
    Intent intent;

    for (const auto& token : tokens) {
        switch (token.type) {
            case stringParser::COMMAND:
                if (intent.action.empty()) intent.action = token.word;
                break;
            case stringParser::FILE_TYPE:
                if (intent.type.empty()) intent.type = token.word;
                break;
            case stringParser::NAME:
                if (intent.name.empty()) intent.name = token.word;
                break;
            default:
                break;
        }
    }

    return intent;
}

void Executor::executeIntent(const Intent& intent) {
    if (intent.action == "make" && intent.type == "folder") {
        fs::create_directory(intent.name);
        std::cout << "✅ Created folder: " << intent.name << "\n";
    } else {
        std::cout << "❌ Unknown action or unsupported type.\n";
    }
    if (intent.action == "delete" || intent.action == "remove" && intent.type == "folder") {
        fs::remove(intent.name);
        std::cout << "✅ deleted folder: " << intent.name << "\n";
    } else {
        std::cout << "❌ Unknown action or unsupported type.\n";
    }
}
