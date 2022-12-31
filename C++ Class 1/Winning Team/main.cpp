#include <iostream>
#include <string>
#include "Team.h"
using namespace std;

int main()
{
    string name;
    int wins;
    int losses;
    Team team;

    cin >> name;
    cin >> wins;
    cin >> losses;

    team.SetName(name);
    team.SetWins(wins);
    team.SetLosses(losses);

    team.PrintStanding();

    return 0;
}