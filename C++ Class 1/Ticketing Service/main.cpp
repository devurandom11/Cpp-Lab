#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string personName = "";
    int youPosition;
    bool seen;

    queue<string> peopleInQueue;

    getline(cin, personName);
    youPosition = 1;
    seen = false;
    while (personName != "-1")
    {
        // TODO: Add personName to peopleInQueue
        //       determine position of "You" (youPosition)
        peopleInQueue.push(personName);
        if (personName != "You" && seen == false)
        {
            youPosition += 1;
        }
        else if (personName == "You")
        {
            seen = true;
        }

        getline(cin, personName);
    }

    cout << "Welcome to the ticketing service... " << endl;
    cout << "You are number " << youPosition << " in the queue." << endl;

    // TODO: In a loop, remove head person from peopleInQueue,
    //       output their name and that they have purchased a ticket,
    //       then output your position in the queue. When you are at
    //       the head, output that you can purchase your ticket.

    for (int i = 0; i < youPosition - 1; ++i)
    {
        cout << peopleInQueue.front() << " has purchased a ticket." << endl;
        peopleInQueue.pop();
        cout << "You are now number " << youPosition - (i + 1) << endl;
    }
    cout << "You can now purchase your ticket!" << endl;

    return 0;
}