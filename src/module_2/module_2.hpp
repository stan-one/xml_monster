#pragma once

#include <vector>

class Module2 {
private:
    std::vector<double> data;
    bool isInitialized;

public:
    // Constructor
    Module2();
    
    // Public methods
    void addData(double value);
    double getAverage() const;
    void clearData();
    bool getStatus() const;
    void initialize();
};
