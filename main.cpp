#include "main.hpp"

int main() {
    // Using Module1
    Module1 mod1("First Module");
    mod1.setValue(42);
    mod1.printInfo();

    // Using Module2
    Module2 mod2;
    mod2.initialize();
    mod2.addData(1.5);
    mod2.addData(2.5);
    cout << "Average: " << mod2.getAverage() << endl;

    XmlHandler handler("people.xml");
    
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