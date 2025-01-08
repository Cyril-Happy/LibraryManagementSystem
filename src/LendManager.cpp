#include "LendManager.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


void print_lend_header();
vector<LendList> extract_lends_from_file(string filename);
void display_lends(vector<LendList> lends);

void LendList::display() const
{
    cout << setw(5) << ser_num
         << setw(10) << book_id
         << setw(10) << reader_id
         << setw(15) << lend_date
         << setw(15) << back_date
         << endl;
}


LendManager::LendManager()
{
}

LendManager::~LendManager()
{
}

void LendManager::loadLendData()
{
    // In a real system, you would load data from ../data/rentals.csv
    vector<LendList> extracted_lends = extract_lends_from_file("../data/rentals.csv");
    lends = extracted_lends;
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

void LendManager::viewLendLogs()
{
    display_lends(lends);
}

vector<LendList> extract_lends_from_file(string filename)
{
    vector<LendList> extracted_lends;
    cout << "[info]Reading from file: " << filename << endl;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file" << endl;
        return extracted_lends;
    }
    // Skip the first line (header)
    string headerLine;
    getline(file, headerLine);
    string line;
    int recordCount = 0; // Variable to count successfully loaded records
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) // getline(stringstream, string, delimiter)
        {
            tokens.push_back(token);
        }

        // Ensure the line contains exactly 5 tokens
        if (tokens.size() != 5)
        {
            cerr << "Error: Invalid data format in line: " << line << endl;
            continue; // Skip the current line
        }
        try
        {
            LendList record;
            record.ser_num = stoll(tokens[0]);
            record.book_id = stoll(tokens[1]);
            record.reader_id = stoll(tokens[2]);
            record.lend_date = tokens[3];
            record.back_date = tokens[4];
            extracted_lends.push_back(record);
            recordCount++;
        }
        catch (const std::exception &e)
        {
            cerr << "Error: Invalid data format in line: " << line << endl;
        }
    }
    cout << "[info]Successfully loaded " << recordCount << " lend records." << endl;
    return extracted_lends;
}

void printLendLine()
{
    for (int i = 0; i < 55; i++)
        cout << "-";
    cout<<endl;
}
void display_lends(vector<LendList> lends)
{
    print_lend_header();
    for (auto &record : lends)
    {
        record.display();
    }
    printLendLine();
}
void print_lend_header()
{
    printLendLine();
    cout << setw(5) << "SerNum"
         << setw(10) << "Book ID"
         << setw(10) << "Reader ID"
         << setw(15) << "Lend Date"
         << setw(15) << "Back Date"
         << endl;
    printLendLine();
}
