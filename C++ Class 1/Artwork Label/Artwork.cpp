#include "Artwork.h"
#include <iostream>

// TODO: Define default constructor
Artwork::Artwork(string inputTitle, int created, Artist inputArtist)
{
    title = inputTitle;
    yearCreated = created;
    artist = inputArtist;
};
// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)
Artwork::Artwork()
{
    title = "";
    yearCreated = -1;
    artist = Artist();
}

// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle() const
{
    return title;
}

int Artwork::GetYearCreated() const
{
    return yearCreated;
}
// TODO: Define PrintInfo() function
void Artwork::PrintInfo() const
{
    artist.PrintInfo();
    cout << "Title: " << title << ", " << yearCreated << endl;
}
//       Call the PrintInfo() function in the Artist class to print an artist's information