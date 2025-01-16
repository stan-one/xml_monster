#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // For std::max_element
#include "../../include/rapidcsv.h" // Include the RapidCSV header
#include "csv_handler.hpp"

// Constructor implementation
csv_handler::csv_handler(const std::string& file) : filename(file) {}

// Method to create a CSV file
void csv_handler::createCSV() const {
    std::ofstream file(filename);

    // Write headers and data
    file << "Name,Score\n";
    file << "Alice,85\n";
    file << "Bob,92\n";
    file << "Charlie,78\n";
    file << "Diana,90\n";

    file.close();
    std::cout << "CSV file '" << filename << "' created.\n";
}

// Method to read and process the CSV file
void csv_handler::processCSV() const {
    try {
        // Load the CSV file using rapidcsv
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1)); // First row as column headers

        // Get the "Score" column
        std::vector<int> scores = doc.GetColumn<int>("Score");

        // Calculate the sum of the scores
        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        std::cout << "The total score is: " << sum << "\n";

        // Find the highest score
        int maxScore = *std::max_element(scores.begin(), scores.end());
        std::cout << "The highest score is: " << maxScore << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}
