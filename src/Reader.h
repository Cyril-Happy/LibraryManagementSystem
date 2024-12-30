#ifndef READER_H
#define READER_H

#include "User.h"

class Reader : public User {
public:
    Reader();
    Reader(long long id, const std::string &uname, const std::string &pwd);
    virtual ~Reader();

    // Override
    virtual void displayInfo() override;

    // Borrow and return book (for demonstration, just print messages)
    void borrowBook();
    void returnBook();
};

#endif
