#ifndef UNTILITY_H
#define UNTILITY_H

#include <iostream>
#include <exception>

class Untility
{
public:
    void logError(std::string errorMassage) {
        throw std::invalid_argument("Error: " + errorMassage);
    }

    void logWarning(std::string warningMassage) {
        std::cout << "Warning: " << warningMassage << std::endl;
    }

    void logMassage(std::string massage) {
        std::cout << massage << std::endl;
    }
};

#endif //UNTILITY_H
