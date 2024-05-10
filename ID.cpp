#include "ID.h"
using namespace std;

ID::ID(){
    static int currentNumber = 10000000;
    ID_number = currentNumber;
    currentNumber++;
    full_ID = "A" + to_string(ID_number);
}

int ID::getIDNumber() const{
    return ID_number;
}

void ID::setIDNumber(int newIDNumber){
    ID_number = newIDNumber;
    full_ID = "A" + to_string(ID_number);
}

string ID::getFullID() const{
    return full_ID;
}

void ID::setFullID(string newFullID){
    full_ID = newFullID;
    string ID_numstring = newFullID.substr(1);
    ID_number = stoi(ID_numstring);
}
