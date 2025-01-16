#pragma once

#include <string>

class csv_handler {
private:
    std::string filename;

public:
    // Constructor to initialize the filename
    explicit csv_handler(const std::string& file);

    // Method to create a CSV file
    void createCSV() const;

    // Method to read and process the CSV file
    void processCSV() const;
};

