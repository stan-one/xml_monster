#include "module_1.hpp"
#include <iostream>

Module1::Module1(const std::string& moduleName) : name(moduleName), value(0) {}

void Module1::setValue(int newValue) {
    value = newValue;
}

int Module1::getValue() const {
    return value;
}

std::string Module1::getName() const {
    return name;
}

void Module1::printInfo() const {
    std::cout << "Module Name: " << name << "\nValue: " << value << std::endl;
}