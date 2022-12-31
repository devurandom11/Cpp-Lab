#include <iostream>
#include <string>

using namespace std;

int DateParser(string month)
{
    int monthInt = 0;

    if (month == "January")
        monthInt = 1;
    else if (month == "February")
        monthInt = 2;
    else if (month == "March")
        monthInt = 3;
    else if (month == "April")
        monthInt = 4;
    else if (month == "May")
        monthInt = 5;
    else if (month == "June")
        monthInt = 6;
    else if (month == "July")
        monthInt = 7;
    else if (month == "August")
        monthInt = 8;
    else if (month == "September")
        monthInt = 9;
    else if (month == "October")
        monthInt = 10;
    else if (month == "November")
        monthInt = 11;
    else if (month == "December")
        monthInt = 12;
    return monthInt;
}

int main()
{
    // TODO: Read dates from input, parse the dates to find the ones
    //       in the correct format, and output in m/d/yyyy format
    string userInput;
    string userMonthString;
    string userYear;
    string userDay;
    int userMonth;

    getline(cin, userInput);
    while (userInput != "-1")
    {
        if (userInput.find(',') != string::npos)
        {
            userMonthString = userInput.substr(0, userInput.find(' '));
            userMonth = DateParser(userMonthString);
            userYear = userInput.substr(userInput.find(',') + 2);
            userDay = userInput.string::substr(userInput.find(' ') + 1, userInput.find(',') - userInput.find(' ') - 1);
            cout << userMonth << "/" << userDay << "/" << userYear << endl;
        }
        // Repeat loop until -1
        getline(cin, userInput);
    }

    return 0;
}
