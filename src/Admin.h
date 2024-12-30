#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin();
    Admin(long long id, const std::string &uname, const std::string &pwd);
    virtual ~Admin();

    // Validates login for admin
    virtual bool validateLogin(const std::string &uname, const std::string &pwd) override;
};

#endif
