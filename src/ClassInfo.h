#ifndef CLASSINFO_H
#define CLASSINFO_H

#include <string>

class ClassInfo {
private:
    int class_id;
    std::string class_name;

public:
    ClassInfo();
    ClassInfo(int c_id, const std::string &c_name);
    ~ClassInfo();

    // Displays classification info
    void display();
};

#endif
