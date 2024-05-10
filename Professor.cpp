#include "Professor.h"
#include <iostream>

using namespace std;

Professor::Professor(string fullName) : UnivMember(fullName, "Professor") {}

Professor::~Professor() {}

void Professor::addCourseTaught(string course) {
    coursesTaught.push_back(course);
}

void Professor::removeCourseTaught(string course) {
    for (auto it = coursesTaught.begin(); it != coursesTaught.end(); ++it) {
        if (*it == course) {
            coursesTaught.erase(it);
            break;
        }
    }
}

void Professor::displayCoursesTaught() const {
    cout << "Courses Taught: ";
    for (const auto& course : coursesTaught) {
        cout << course << " ";
    }
    cout << endl;
}

vector<string> Professor::getCoursesTaught() const {
    return coursesTaught;
}