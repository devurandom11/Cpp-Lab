#include "OfferedCourse.h"

// TODO: Define mutator functions -
//      SetInstructorName(), SetTerm(), SetClassTime()
void OfferedCourse::SetInstructorName(string instructorName)
{
    this->instructorName = instructorName;
}

void OfferedCourse::SetTerm(string term)
{
    this->term = term;
}

void OfferedCourse::SetClassTime(string classTime)
{
    this->classTime = classTime;
}

// TODO: Define accessor functions -
//      GetInstructorName(), GetTerm(), GetClassTime()
string OfferedCourse::GetInstructorName()
{
    return this->instructorName;
}

string OfferedCourse::GetTerm()
{
    return this->term;
}

string OfferedCourse::GetClassTime()
{
    return this->classTime;
}