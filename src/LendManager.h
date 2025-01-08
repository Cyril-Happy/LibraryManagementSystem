#ifndef LENDMANAGER_H
#define LENDMANAGER_H

#include <vector>
#include <string>

using namespace std;
// Records of borrowing
struct LendList {
    long long ser_num;
    long long book_id;
    long long reader_id;
    std::string lend_date;
    std::string back_date;

    void display() const;
};

class LendManager {
private:
    std::vector<LendList> lends;

public:
    LendManager();
    ~LendManager();
    void loadLendData();
    // Adds a lend record
    void addLend(long long serNum, long long bID, long long rID,
                 const std::string &lendDate, const std::string &backDate);

    // Updates the back_date of a lend record
    void returnBook(long long serNum, const std::string &backDate);

    // Displays all lend logs
    void viewLendLogs();
};

#endif
