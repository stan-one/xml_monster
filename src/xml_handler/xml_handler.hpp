// xml_handler.hpp
#pragma once

#include "../../include/tinyxml2.h"
#include <string>
#include <vector>

class XmlHandler {
private:
    tinyxml2::XMLDocument doc;
    std::string filename;

public:
    struct PersonData {
        std::string name;
        int age;
        std::string occupation;
    };

    XmlHandler(const std::string& file);
    
    // Create a new XML file with some sample data
    bool createSampleXml(const std::vector<PersonData>& people);
    
    // Load existing XML file
    bool loadXml();
    
    // Add a new person to the XML
    bool addPerson(const PersonData& person);
    
    // Save the XML to file
    bool saveXml();
    
    // Print XML content
    void printXml() const;
};
