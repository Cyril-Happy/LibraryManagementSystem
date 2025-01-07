#include "User.h"
#include <iostream>

// Default constructor
User::User() : user_id(0), username(""), password(""), role("") {
}

// Parameterized constructor
User::User(long long id, const std::string &uname, const std::string &pwd, const std::string &r)
    : user_id(id), username(uname), password(pwd), role(r) {
}

// Destructor
User::~User() {
}

// Validate login by checking username and password
bool User::validateLogin(const long long &id , const std::string &pwd) const {
    return (user_id == id && password == pwd);
}

// Display user information
void User::displayInfo() const {
    std::cout << "User ID: " << user_id << "\nUsername: " << username << "\nRole: " << role << std::endl;
}

// Getters
long long User::getUserId() const {
    return user_id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getRole() const {
    return role;
}

// Setters
void User::setUserId(long long id) {
    user_id = id;
}

void User::setUsername(const std::string &uname) {
    username = uname;
}

void User::setPassword(const std::string &pwd) {
    password = pwd;
}

void User::setRole(const std::string &r) {
    role = r;
}
