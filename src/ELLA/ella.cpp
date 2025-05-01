#include <ELLA/ella.h>
#include <iostream>
#include <string>

void ella::init() {
    if (!introduced) {
        std::cout << "hello my name is ELLA (" << ELLA_VERSION << ") or Enhanced Language & Logic Assistant \n";
        introduced = true;
    }
    std::cout << "How can i help you? \n";
    std::string userInput = getUserInput();
    std::cout << userInput;
    SP.init(userInput);
    for (const auto& token : SP.getTokens()) {
        std::cout << token.word << " -> " << token.type << '\n';
    }
    Intent intent = EX.parseIntent(SP.getTokens());
    EX.executeIntent(intent);
    init();

}

std::string ella::getUserInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}