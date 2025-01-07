#include "LendManager.h"
#include <iostream>

void LendList::display() const
{
    std::cout << "SerNum: " << ser_num
              << ", Book ID: " << book_id
              << ", Reader ID: " << reader_id
              << ", Lend Date: " << lend_date
              << ", Back Date: " << back_date << std::endl;
}

LendManager::LendManager()
{
}

LendManager::~LendManager()
{
}

void LendManager::addLend(long long serNum, long long bID, long long rID,
                          const std::string &lendDate, const std::string &backDate)
{
    LendList record;
    record.ser_num = serNum;
    record.book_id = bID;
    record.reader_id = rID;
    record.lend_date = lendDate;
    record.back_date = backDate;
    lends.push_back(record);
}

void LendManager::returnBook(long long serNum, const std::string &backDate)
{
    for (auto &record : lends)
    {
        if (record.ser_num == serNum)
        {
            record.back_date = backDate;
            break;
        }
    }
}

void LendManager::viewLogs()
{
    for (auto &record : lends)
    {
        record.display();
    }
}
