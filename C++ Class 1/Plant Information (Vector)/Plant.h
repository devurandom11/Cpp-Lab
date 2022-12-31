#ifndef PLANTH
#define PLANTH

#include <string>
using namespace std;

class Plant
{
public:
    virtual ~Plant();

    void SetPlantName(string userPlantName);

    string GetPlantName() const;

    void SetPlantCost(int userPlantCost);

    int GetPlantCost() const;

    virtual void PrintInfo() const;

protected:
    string plantName;
    int plantCost;
};

#endif