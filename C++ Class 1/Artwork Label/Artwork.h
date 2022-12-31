#ifndef ARTWORKH
#define ARTWORKH

#include "Artist.h"

class Artwork
{
public:
    Artwork();

    Artwork(string title, int yearCreated, Artist artist);

    string GetTitle() const;

    int GetYearCreated() const;

    void PrintInfo() const;

private:
    // TODO: Declare private data members - title, yearCreated
    string title = "";
    int yearCreated = -1;
    // TODO: Declare private data member artist of type Artist
    Artist artist;
};

#endif
