#ifndef MENU_H
#define MENU_H

#include "AdminManager.h"

// Provides the main menu for the system
class Menu {
private:
    bool adminLoggedIn;
    AdminManager adminManager;

public:
    Menu();
    ~Menu();

    // Shows the main menu
    void displayMainMenu();

    // Admin login and logout
    void login();
    void logout();

    // Main loop
    void run();
};

#endif
