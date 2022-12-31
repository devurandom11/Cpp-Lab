#include "Artist.h"
#include "Artwork.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userTitle, userArtistName;
    int yearCreated, userBirthYear, userDeathYear;

    getline(cin, userArtistName);
    cin >> userBirthYear;
    cin.ignore();
    cin >> userDeathYear;
    cin.ignore();
    getline(cin, userTitle);
    cin >> yearCreated;
    cin.ignore();

    Artist userArtist = Artist(userArtistName, userBirthYear, userDeathYear);

    Artwork newArtwork = Artwork(userTitle, yearCreated, userArtist);

    newArtwork.PrintInfo();
}