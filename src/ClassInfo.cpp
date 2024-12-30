#include "ClassInfo.h"
#include <iostream>

ClassInfo::ClassInfo() : class_id(0), class_name("") {
}

ClassInfo::ClassInfo(int c_id, const std::string &c_name)
    : class_id(c_id), class_name(c_name) {
}

ClassInfo::~ClassInfo() {
}

void ClassInfo::display() {
    std::cout << "Class ID: " << class_id 
              << "\nClass Name: " << class_name << std::endl;
}
