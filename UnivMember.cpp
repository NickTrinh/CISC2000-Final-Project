//Nick Trinh
#include "UnivMember.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

UnivMember::UnivMember(){
    setUnivName("");
    setRole("");

}

UnivMember::UnivMember(string fullName, string role){
    setUnivName(fullName);
    setRole(role);

}

UnivMember::~UnivMember() {}

void UnivMember::display() const {
    cout << "Name: " << univName.getFirstName() << " " << univName.getLastName() << endl;
    cout << "ID: " << univID.getFullID() << endl;
    cout << "Role: " << role << endl;
}

void UnivMember::setUnivID(string id) {
    univID.setFullID(id);
}

void UnivMember::setUnivName(string fullName) {
    Name name(fullName);
    univName = name;
}

void UnivMember::setRole(string role) {
    this->role = role;
}

string UnivMember::getUnivID() const {
    return univID.getFullID();
}

string UnivMember::getFirstName() const {
    return univName.getFirstName();
}

string UnivMember::getLastName() const {
    return univName.getLastName();
}

string UnivMember::getRole() const {
    return role;
}
