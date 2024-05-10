#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(){
    subject = "";
    courseNumber = "";
    section = "";
    description = "";
    hours = 0;
    crn = "";
    term = "";
    instructor = "";
    meetingTimes = "";
    time = "";

}

Course::Course(string subject, string courseNumber, string section, string description, int hours, string crn, string term, string instructor, string meetingTimes, string time)
{
    this->subject = subject;
    this->courseNumber = courseNumber;
    this->section = section;
    this->description = description;
    this->hours = hours;
    this->crn = crn;
    this->term = term;
    this->instructor = instructor;
    this->meetingTimes = meetingTimes;
    this->time = time;

}

Course::~Course() {}

string Course::getCRN() const {
        return crn;
}

string Course::getInstructor() const {
    return instructor;
}

string Course::getDescription() const {
    return description;
}

void Course::display() const {
    cout << "Subject: " << subject << endl;
    cout << "Course Number: " << courseNumber << endl;
    cout << "Section: " << section << endl;
    cout << "Description: " << description << endl;
    cout << "Hours: " << hours << endl;
    cout << "CRN: " << crn << endl;
    cout << "Term: " << term << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Meeting Times: " << meetingTimes << endl;
    cout << "Time: " << time << endl <<endl;
}