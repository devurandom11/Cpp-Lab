#include <iostream>
#include <iomanip>
#include "Team.h"
using namespace std;

// TODO: Implement mutator functions -
//       SetName(), SetWins(), SetLosses()
void Team::SetName(string inputName)
{
    name = inputName;
}

void Team::SetWins(int inputWins)
{
    wins = inputWins;
}

void Team::SetLosses(int inputLosses)
{
    losses = inputLosses;
}
// TODO: Implement accessor functions -
//       GetName(), GetWins(), GetLosses()
string Team::GetName() const
{
    return name;
}

int Team::GetWins() const
{
    return wins;
}

int Team::GetLosses() const
{
    return losses;
}

// TODO: Implement GetWinPercentage()
double Team::GetWinPercentage() const
{
    double winPercentage = static_cast<double>(wins) / static_cast<double>(wins + losses);
    return winPercentage;
}
// TODO: Implement PrintStanding()
void Team::PrintStanding()
{
    double winPercentage = GetWinPercentage();
    cout << fixed << setprecision(2);
    cout << "Win percentage: " << winPercentage << endl;
    if (winPercentage > .5)
    {
        cout << "Congratulations, Team " << name << " has a winning average!" << endl;
    }
    else
    {
        cout << "Team " << name << " has a losing average." << endl;
    }
}