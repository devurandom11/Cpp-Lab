#ifndef FLOWERH
#define FLOWERH

#include "Plant.h"
#include <string>


class Flower : public Plant
{
public:
    void SetPlantType(bool userIsAnnual);

    bool GetPlantType() const;

    void SetColorOfFlowers(std::string userColorOfFlowers);

    std::string GetColorOfFlowers() const;

    void PrintInfo() const;

private:
    bool isAnnual;
    std::string colorOfFlowers;
};

#endif
