#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>

// Forward declaration or include "User.h" if needed
#include "User.h"

class UserManager
{
private:
    std::vector<User> users;

public:
    UserManager();
    ~UserManager();
    void loadUserData();
    // Validate login credentials
    User validateLogin(const long long &id, const std::string &password);

};
#endif
