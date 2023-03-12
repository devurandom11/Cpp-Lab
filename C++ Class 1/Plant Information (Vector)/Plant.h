#ifndef PLANTH
#define PLANTH

#include <string>


class Plant
{
public:
    virtual ~Plant();

    void SetPlantName(std::string userPlantName);

    std::string GetPlantName() const;

    void SetPlantCost(int userPlantCost);

    int GetPlantCost() const;

    virtual void PrintInfo() const;

protected:
    std::string plantName;
    int plantCost;
};

#endif
