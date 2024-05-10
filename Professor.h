//Nick Trinh
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UnivMember.h"
#include <vector>
#include <string>

using namespace std;

class Professor : public UnivMember {
private:
    vector<string> coursesTaught;

public:
    Professor(string fullName);
    ~Professor();

    void addCourseTaught(string course);
    void removeCourseTaught(string course);
    void displayCoursesTaught() const;
    vector<string> getCoursesTaught() const;
    
    using UnivMember::getFirstName;
    using UnivMember::getLastName;
    using UnivMember::getUnivID;
    using UnivMember::getRole;
};

#endif