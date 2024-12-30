#include "ReaderManager.h"
#include <iostream>

void ReaderInfo::display() const {
    std::cout << "Reader ID: " << reader_id 
              << ", Name: " << name
              << ", Sex: " << sex
              << ", Birth: " << birth
              << ", Address: " << address
              << ", Phone: " << phone << std::endl;
}

void ReaderCard::display() const {
    std::cout << "Reader ID: " << reader_id
              << ", Username: " << username
              << ", Password: " << password << std::endl;
}

ReaderManager::ReaderManager() {
}

ReaderManager::~ReaderManager() {
}

void ReaderManager::addReader(long long id, const std::string &name, const std::string &sex,
                              const std::string &birth, const std::string &address, const std::string &phone,
                              const std::string &username, const std::string &password) {
    ReaderInfo info;
    info.reader_id = id;
    info.name = name;
    info.sex = sex;
    info.birth = birth;
    info.address = address;
    info.phone = phone;
    readerInfos.push_back(info);

    ReaderCard card;
    card.reader_id = id;
    card.username = username;
    card.password = password;
    readerCards.push_back(card);
}

void ReaderManager::deleteReader(long long id) {
    for (auto it = readerInfos.begin(); it != readerInfos.end(); ) {
        if (it->reader_id == id) {
            it = readerInfos.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = readerCards.begin(); it != readerCards.end(); ) {
        if (it->reader_id == id) {
            it = readerCards.erase(it);
        } else {
            ++it;
        }
    }
}

void ReaderManager::searchReaders(const std::string &keyword) {
    for (auto &info : readerInfos) {
        // Basic matching on ID or other fields
        if (std::to_string(info.reader_id).find(keyword) != std::string::npos ||
            info.name.find(keyword) != std::string::npos ||
            info.sex.find(keyword) != std::string::npos ||
            info.birth.find(keyword) != std::string::npos ||
            info.address.find(keyword) != std::string::npos ||
            info.phone.find(keyword) != std::string::npos) {
            info.display();
        }
    }
}

void ReaderManager::printReaders() {
    for (auto &info : readerInfos) {
        info.display();
    }
}
