#ifndef READERMANAGER_H
#define READERMANAGER_H

#include <vector>
#include <string>

// Forward declaration or include "Reader.h" if needed
#include "Reader.h"

// Reader information table
struct ReaderInfo {
    long long reader_id;
    std::string name;
    std::string sex;
    std::string birth;
    std::string address;
    std::string phone;

    void display() const;
};

// Reader card table
struct ReaderCard {
    long long reader_id;
    std::string password;
    std::string username;

    void display() const;
};

class ReaderManager {
private:
    std::vector<ReaderInfo> readerInfos;
    std::vector<ReaderCard> readerCards;

public:
    ReaderManager();
    ~ReaderManager();

    // Adds a new reader
    void addReader(long long id, const std::string &name, const std::string &sex,
                   const std::string &birth, const std::string &address, const std::string &phone,
                   const std::string &username, const std::string &password);

    // Deletes reader by ID
    void deleteReader(long long id);

    // Searches reader by keyword (could be ID, name, etc.)
    void searchReaders(const std::string &keyword);

    // Prints all readers
    void printReaders();
};

#endif
