#include <iostream>
#include <string>

using namespace std;

int main()
{

    /* Type your code here. */
    string BFF = "best friend forever";
    string IDK = "I don't know";
    string JK = "just kidding";
    string TMI = "too much information";
    string TTYL = "talk to you later";
    string message;

    cout << "Enter text:" << endl;
    getline(cin, message);

    unsigned long bffSearch = message.find("BFF");
    unsigned long idkSearch = message.find("IDK");
    unsigned long jkSearch = message.find("JK");
    unsigned long tmiSearch = message.find("TMI");
    unsigned long ttylSearch = message.find("TTYL");

    cout << "You entered: " << message << endl;

    if (bffSearch != string::npos)
    {
        cout << "BFF: " << BFF << endl;
    }
    if (idkSearch != string::npos)
    {
        cout << "IDK: " << IDK << endl;
    }
    if (jkSearch != string::npos)
    {
        cout << "JK: " << JK << endl;
    }
    if (tmiSearch != string::npos)
    {
        cout << "TMI: " << TMI << endl;
    }
    if (ttylSearch != string::npos)
    {
        cout << "TTYL: " << TTYL << endl;
    }

    return 0;
}