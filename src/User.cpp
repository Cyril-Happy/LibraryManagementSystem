#include "User.h"
#include <iostream>

User::User() : user_id(0), username(""), password(""), role("") {
}

User::User(long long id, const std::string &uname, const std::string &pwd, const std::string &r)
    : user_id(id), username(uname), password(pwd), role(r) {
}

User::~User() {
}

bool User::validateLogin(const std::string &uname, const std::string &pwd) {
    // Basic validation against stored username/password
    return (username == uname && password == pwd);
}

void User::displayInfo() {
    std::cout << "User ID: " << user_id << "\nUsername: " << username 
              << "\nRole: " << role << std::endl;
}

long long User::getUserId() const {
    return user_id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getRole() const {
    return role;
}
