#include "Admin.h"

Admin::Admin() : User(0, "", "", "admin") {
}

Admin::Admin(long long id, const std::string &uname, const std::string &pwd)
    : User(id, uname, pwd, "admin") {
}

Admin::~Admin() {
}

bool Admin::validateLogin(const std::string &uname, const std::string &pwd) {
    // Could add additional admin-specific checks if needed
    return User::validateLogin(uname, pwd);
}
