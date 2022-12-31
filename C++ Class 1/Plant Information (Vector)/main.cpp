#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void PrintVector(vector<Plant *> &v)
{
    for (auto &plant : v)
    {
        plant->PrintInfo();
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<Plant *> myGarden;

    // declare variables
    string plantName, flowerName, colorOfFlowers;
    int plantCost, flowerCost;
    string isAnnual;

    string input;
    cin >> input;

    while (input != "-1")
    {
        if (input == "plant")
        {
            // read and set the info of plant
            cin >> plantName >> plantCost;
            Plant *p = new Plant();
            p->SetPlantName(plantName);
            p->SetPlantCost(plantCost);

            myGarden.push_back(p);
        }
        else
        {
            // read and set the info of flower
            cin >> flowerName >> flowerCost >> isAnnual >> colorOfFlowers;
            Flower *f = new Flower();

            f->SetPlantName(flowerName);
            f->SetPlantCost(flowerCost);
            if (isAnnual == "false")
                f->SetPlantType(false);
            else
                f->SetPlantType(true);
            f->SetColorOfFlowers(colorOfFlowers);

            myGarden.push_back(f);
        }
        cin >> input;
    }

    PrintVector(myGarden);
}