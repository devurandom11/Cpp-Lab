#include <map>
#include <string>
#include <iostream>

int main()
{
    std::string studentName;
    double studentGrade;

    std::map<std::string, double> studentGrades;

    // Students' grades (pre-entered)
    studentGrades.emplace("Harry Rawlins", 84.3);
    studentGrades.emplace("Stephanie Kong", 91.0);
    studentGrades.emplace("Shailen Tennyson", 78.6);
    studentGrades.emplace("Quincy Wraight", 65.4);
    studentGrades.emplace("Janine Antinori", 98.2);

    // Read in new grade for a student, output initial grade, replace with new grade in map, output new grade
    std::getline(std::cin, studentName);
    std::cin >> studentGrade;

    std::cout << studentName << "'s original grade: " << studentGrades.at(studentName) << '\n';

    studentGrades[studentName] = studentGrade;
    std::cout << studentName << "'s new grade: " << studentGrade << '\n';

    return 0;
}
