#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    long long user_id;
    std::string username;
    std::string password;
    std::string role; // "admin" or "reader"

public:
    User();
    User(long long id, const std::string &uname, const std::string &pwd, const std::string &r);
    virtual ~User();

    // Validates user login
    virtual bool validateLogin(const std::string &uname, const std::string &pwd);

    // Displays user information (virtual function, can be overridden)
    virtual void displayInfo();

    // Getters
    long long getUserId() const;
    std::string getUsername() const;
    std::string getRole() const;
};

#endif
