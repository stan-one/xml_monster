#include "module_2.hpp"
#include <numeric>
#include <stdexcept>

Module2::Module2() : isInitialized(false) {}

void Module2::initialize() {
    isInitialized = true;
}

void Module2::addData(double value) {
    if (!isInitialized) {
        throw std::runtime_error("Module not initialized");
    }
    data.push_back(value);
}

double Module2::getAverage() const {
    if (data.empty()) {
        return 0.0;
    }
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

void Module2::clearData() {
    data.clear();
}

bool Module2::getStatus() const {
    return isInitialized;
}
