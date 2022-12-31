#include "Encyclopedia.h"
#include <iostream>

// Define functions declared in Encyclopedia.h
void Encyclopedia::SetEdition(string edition)
{
    this->edition = edition;
}

void Encyclopedia::SetNumVolumes(int numVolumes)
{
    this->numVolumes = numVolumes;
}

string Encyclopedia::GetEdition()
{
    return this->edition;
}

int Encyclopedia::GetNumVolumes()
{
    return this->numVolumes;
}

void Encyclopedia::PrintInfo()
{
    cout << "Encyclopedia Information: " << endl;
    cout << "   Book Title: " << this->title << endl;
    cout << "   Author: " << this->author << endl;
    cout << "   Publisher: " << this->publisher << endl;
    cout << "   Publication Date: " << this->publicationDate << endl;
    cout << "   Edition: " << this->edition << endl;
    cout << "   Volume Number: " << this->numVolumes << endl;
}