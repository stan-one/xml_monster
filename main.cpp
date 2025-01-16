#include "main.hpp"

int main() {
    // Create an instance of the CSVHandler class
    csv_handler csvHandler("../test_room/test.csv");

    // Create and process the CSV file
    //csvHandler.createCSV();
    csvHandler.processCSV();

    XmlHandler handler("../test_room/people.xml");
    
    // Create sample data
    std::vector<XmlHandler::PersonData> people = {
        {"John Doe", 30, "Developer"},
        {"Jane Smith", 28, "Designer"},
        {"Bob Johnson", 45, "Manager"}
    };
    
    // Create and save XML
    if (handler.createSampleXml(people)) {
        std::cout << "XML file created successfully!\n\n";
        std::cout << "XML Content:\n";
        handler.printXml();
    }
    
    // Add another person
    XmlHandler::PersonData newPerson = {"Alice Brown", 35, "Engineer"};
    if (handler.loadXml() && handler.addPerson(newPerson) && handler.saveXml()) {
        std::cout << "\nUpdated XML Content:\n";
        handler.printXml();
    }
    
}