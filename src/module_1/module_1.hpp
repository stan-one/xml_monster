#pragma once 

#include <string>

class Module1 {
private:
    std::string name;
    int value;

public:
    // Constructor
    Module1(const std::string& moduleName);
    
    // Public methods
    void setValue(int newValue);
    int getValue() const;
    std::string getName() const;
    void printInfo() const;
};