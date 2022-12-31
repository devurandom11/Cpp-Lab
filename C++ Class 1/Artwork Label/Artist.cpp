#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Define default constructor
Artist::Artist(string name, int birth, int death)
{
    artistName = name;
    birthYear = birth;
    deathYear = death;
}
// TODO: Define second constructor to initialize
//       private fields (artistName, birthYear, deathYear)
Artist::Artist()
{
    artistName;
    birthYear;
    deathYear;
}
// TODO: Define get functions: GetName(), GetBirthYear(), GetDeathYear()
string Artist::GetName() const
{
    return artistName;
}

int Artist::GetBirthYear() const
{
    return birthYear;
}

int Artist::GetDeathYear() const
{
    return deathYear;
}
// TODO: Define PrintInfo() function
void Artist::PrintInfo() const
{
    if (deathYear == -1 && birthYear != -1)
    {
        cout << "Artist: " << artistName << " (" << birthYear << " to present)" << endl;
    }
    else if (deathYear != -1 && birthYear != -1)
    {
        cout << "Artist: " << artistName << " (" << birthYear << " to " << deathYear << ")" << endl;
    }
    else
    {
        cout << "Artist: " << artistName << " (unknown)" << endl;
    }
}