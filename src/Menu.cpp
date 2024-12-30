#include "Menu.h"
#include <iostream>
#include <limits>

Menu::Menu() : adminLoggedIn(false)
{
}

Menu::~Menu()
{
}

void Menu::displayMainMenu()
{
    std::cout << "\n---------- Main Menu ----------" << std::endl;
    std::cout << "1. Login (管理员登录)" << std::endl;
    std::cout << "2. Logout (退出登录)" << std::endl;
    std::cout << "3. Add Book (添加图书)" << std::endl;
    std::cout << "4. Delete Book (删除图书)" << std::endl;
    std::cout << "5. Search Books (搜索图书)" << std::endl;
    std::cout << "6. Print Books (打印所有图书信息)" << std::endl;
    std::cout << "7. Add Reader (添加读者)" << std::endl;
    std::cout << "8. Delete Reader (删除读者)" << std::endl;
    std::cout << "9. Search Readers (搜索读者)" << std::endl;
    std::cout << "10. Print Readers (打印所有读者信息)" << std::endl;
    std::cout << "11. View Lend Logs (查看借还日志)" << std::endl;
    std::cout << "0. Exit (退出)" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void Menu::login()
{
    // In a real system, you would check username/password
    // Here we just set adminLoggedIn to true
    adminLoggedIn = true;
    std::cout << "Admin logged in successfully." << std::endl;
}

void Menu::logout()
{
    adminLoggedIn = false;
    std::cout << "Admin logged out." << std::endl;
}

void Menu::run()
{
    int choice = -1;
    while (choice != 0)
    {
        displayMainMenu();
        std::cout << "Please choose an option: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            // Clear error flags
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            logout();
            break;
        case 3:
            if (adminLoggedIn)
            {
                adminManager.addBook();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 4:
            if (adminLoggedIn)
            {
                adminManager.deleteBook();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 5:
            if (adminLoggedIn)
            {
                adminManager.searchBooks();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 6:
            if (adminLoggedIn)
            {
                adminManager.printBooks();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 7:
            if (adminLoggedIn)
            {
                adminManager.addReader();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 8:
            if (adminLoggedIn)
            {
                adminManager.deleteReader();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 9:
            if (adminLoggedIn)
            {
                adminManager.searchReaders();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 10:
            if (adminLoggedIn)
            {
                adminManager.printReaders();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 11:
            if (adminLoggedIn)
            {
                adminManager.viewLogs();
            }
            else
            {
                std::cout << "Please login first." << std::endl;
            }
            break;
        case 0:
            std::cout << "Exiting the system..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    }
}
