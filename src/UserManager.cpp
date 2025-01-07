#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "User.h"
using namespace std;

// Constructor
UserManager::UserManager() {}

// Destructor
UserManager::~UserManager() {}

// load user data from ../data/users.csv
// Function to load user data from a CSV file
void UserManager::loadUserData()
{
    string filename = "../data/users.csv";
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "[error] Could not open the file: " << filename << endl;
        return;
    }
    string headerLine;
    getline(file, headerLine); // Read and ignore the header line
    string line;
    int loaded_users = 0;
    while (getline(file, line))
    {
        string token;
        vector<string> tokens;
        stringstream ss(line);
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        if (tokens.size() != 4)
        {
            cerr << "[error] Invalid data format in line: " << line << endl;
            continue;
        }
        try
        {
            long long id = stoll(tokens[0]);
            string uname = tokens[1];
            string pwd = tokens[2];
            string role = tokens[3];
            User user(id, uname, pwd, role);
            users.push_back(user);
            loaded_users++;
        }
        catch (const invalid_argument &e)
        {
            cerr << "[error] Invalid number format in line: " << line << endl;
        }
        catch (const out_of_range &e)
        {
            cerr << "[error] Number out of range in line: " << line << endl;
        }
    }

    file.close();
    if (loaded_users == 0)
    {
        cerr << "[error] No users loaded." << endl;
    }
    else
    {
        cout << "[info] Successfully Loaded " << loaded_users << " users." << endl;
    }
}
User UserManager::validateLogin(const long long &id, const string &password)
{
    for (const auto &user : users)
    {
        if (user.validateLogin(id, password))
        {
            return user;
        }
    }
    return User(); // Return an empty User object if not found
}
