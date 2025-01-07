#ifndef USER_H
#define USER_H

#include <string>

class User
{
private:
    long long user_id;    // Unique ID for the user
    std::string username; // Username for login
    std::string password; // User's password
    std::string role;     // User role (e.g., "admin", "reader")

public:
    // Constructors
    User();
    User(long long id, const std::string &uname, const std::string &pwd, const std::string &r);
    ~User();

    // Validates user login (checks username and password)
    bool validateLogin(const long long &id, const std::string &pwd) const;

    // Displays user information
    void displayInfo() const;

    // Getters
    long long getUserId() const;
    std::string getUsername() const;
    std::string getRole() const;

    // Setters
    void setUserId(long long id);
    void setUsername(const std::string &uname);
    void setPassword(const std::string &pwd);
    void setRole(const std::string &r);
};

#endif
