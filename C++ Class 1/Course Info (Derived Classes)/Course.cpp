#include "Course.h"

// TODO: Define mutator functions -
//       SetCourseNumber(), SetCourseTitle()
void Course ::SetCourseNumber(string courseNumber)
{
    this->courseNumber = courseNumber;
}

void Course ::SetCourseTitle(string courseTitle)
{
    this->courseTitle = courseTitle;
}
// TODO: Define accessor functions -
//       GetCourseNumber(), GetCourseTitle()
string Course ::GetCourseNumber()
{
    return this->courseNumber;
}

string Course ::GetCourseTitle()
{
    return this->courseTitle;
}
// TODO: Define PrintInfo()

void Course ::PrintInfo()
{
    cout << "Course Information: " << endl;
    cout << "   Course Number: " << this->GetCourseNumber() << endl;
    cout << "   Course Title: " << this->GetCourseTitle() << endl;
}