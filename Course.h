#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course {
private:
    string subject;
    string courseNumber;
    string section;
    string description;
    int hours;
    string crn;
    string term;
    string instructor;
    string meetingTimes;
    string time;

public:
    Course();
    Course(string subject, string courseNumber, string section, string description, int hours, string crn, string term, string instructor, string meetingTimes, string time);
    ~Course();

    string getCRN() const;
    string getInstructor() const;
    string getDescription() const;
    void display() const;
};

#endif