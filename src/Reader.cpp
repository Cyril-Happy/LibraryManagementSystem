#include "Reader.h"
#include <iostream>

Reader::Reader() : User(0, "", "", "reader") {
}

Reader::Reader(long long id, const std::string &uname, const std::string &pwd)
    : User(id, uname, pwd, "reader") {
}

Reader::~Reader() {
}

void Reader::displayInfo() {
    std::cout << "Reader ID: " << getUserId() 
              << "\nUsername: " << getUsername() << std::endl;
}

void Reader::borrowBook() {
    std::cout << "Reader borrowing book..." << std::endl;
}

void Reader::returnBook() {
    std::cout << "Reader returning book..." << std::endl;
}
