//Nick Trinh
#ifndef UNIVMEMBER_H
#define UNIVMEMBER_H

#include "ID.h"
#include "Name.h"
#include <string>

using namespace std;

class UnivMember {
private:
    ID univID;
    Name univName;
    string role;

public:
    UnivMember();
    UnivMember(string fullName, string role);
    ~UnivMember();

    void display() const;
    void setUnivID(string id);
    void setUnivName(string fullName);
    void setRole(string role);

    string getUnivID() const;
    string getFirstName() const;
    string getLastName() const;
    string getRole() const;
};

#endif
