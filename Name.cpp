//Nick Trinh
#include "Name.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

Name::Name(){
    firstName = "First";
    lastName = "Last";
}

Name::Name(string fullName){
    fullName = regex_replace(fullName, std::regex("\\s+"), "");//Delete all spaces
    fullName = regex_replace(fullName, std::regex("\""), "");//Delete all quotes
    //cout<<fullName<<endl;
    istringstream ss(fullName);
    string lastN, firstN;
    getline(ss, lastN, ',');
    getline(ss, firstN);
    lastN = regex_replace(lastN, std::regex("\\s+"), "");//Delete all spaces
    firstN = regex_replace(firstN, std::regex("\""), "");//Delete all quotes
    //cout<<firstN<<" "<<lastN<<endl;
	setFirstName(firstN);
	setLastName(lastN);
}

void Name::setFirstName(string first){
    firstName = first;
}

void Name::setLastName(string last){
    lastName = last;
}

string Name::getFirstName() const{
    return firstName;
}

string Name::getLastName() const{
    return lastName;
}

void Name::printName() const{
    cout << firstName<< " " << lastName << endl;
}

