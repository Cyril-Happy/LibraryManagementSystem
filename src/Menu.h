#ifndef MENU_H
#define MENU_H

#include "AdminManager.h"

// Provides the main menu for the system
class Menu {
private:
    bool isLoggedIn;
    bool isAdmin;
    AdminManager adminManager;

public:
    Menu();
    ~Menu();

    // Shows the main menu
    void displayMainMenu();
    void switch_based_on_role(int &choice);

    // Admin login and logout
    void login();
    void logout();

    // Main loop
    void run();
};

#endif
