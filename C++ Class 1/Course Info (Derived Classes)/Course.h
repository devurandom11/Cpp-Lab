#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course
{
    // TODO: Declare private data members - courseNumber, courseTitle
private:
    string courseNumber;
    string courseTitle;
    // TODO: Declare mutator functions -
    //       SetCourseNumber(), SetCourseTitle()
public:
    void SetCourseNumber(string);
    void SetCourseTitle(string);
    // TODO: Declare accessor functions -
    //       GetCourseNumber(), GetCourseTitle()
    string GetCourseNumber();
    string GetCourseTitle();
    // TODO: Declare PrintInfo()
    void PrintInfo();
};

#endif
