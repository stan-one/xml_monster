// xml_handler.cpp
#include "xml_handler.hpp"
#include <iostream>

XmlHandler::XmlHandler(const std::string& file) : filename(file) {}

bool XmlHandler::createSampleXml(const std::vector<PersonData>& people) {
    // Clear any existing document
    doc.Clear();

    // Create declaration
    tinyxml2::XMLDeclaration* decl = doc.NewDeclaration();
    doc.InsertFirstChild(decl);

    // Create root element
    tinyxml2::XMLElement* root = doc.NewElement("People");
    doc.InsertEndChild(root);

    // Add people to the XML
    for (const auto& person : people) {
        if (!addPerson(person)) {
            return false;
        }
    }

    return saveXml();
}

bool XmlHandler::loadXml() {
    tinyxml2::XMLError result = doc.LoadFile(filename.c_str());
    return result == tinyxml2::XML_SUCCESS;
}

bool XmlHandler::addPerson(const PersonData& person) {
    tinyxml2::XMLElement* root = doc.RootElement();
    if (!root) {
        root = doc.NewElement("People");
        doc.InsertEndChild(root);
    }

    tinyxml2::XMLElement* personElement = doc.NewElement("Person");
    
    // Add name
    tinyxml2::XMLElement* nameElement = doc.NewElement("Name");
    nameElement->SetText(person.name.c_str());
    personElement->InsertEndChild(nameElement);

    // Add age
    tinyxml2::XMLElement* ageElement = doc.NewElement("Age");
    ageElement->SetText(person.age);
    personElement->InsertEndChild(ageElement);

    // Add occupation
    tinyxml2::XMLElement* occupationElement = doc.NewElement("Occupation");
    occupationElement->SetText(person.occupation.c_str());
    personElement->InsertEndChild(occupationElement);

    root->InsertEndChild(personElement);
    return true;
}

bool XmlHandler::saveXml() {
    tinyxml2::XMLError result = doc.SaveFile(filename.c_str());
    return result == tinyxml2::XML_SUCCESS;
}

void XmlHandler::printXml() const {
    tinyxml2::XMLPrinter printer;
    doc.Print(&printer);
    std::cout << printer.CStr() << std::endl;
}