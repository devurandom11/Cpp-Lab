#ifndef TEAMH
#define TEAMH

#include <string>

using namespace std;

class Team
{
private:
    string name = "";
    int wins = -1;
    int losses = -1;

public:
    void SetName(string name);
    void SetWins(int wins);
    void SetLosses(int losses);

    string GetName() const;
    int GetWins() const;
    int GetLosses() const;

    double GetWinPercentage() const;

    void PrintStanding();
};

#endif