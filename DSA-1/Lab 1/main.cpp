#include <iostream>
#include <string>
#include "LabPrinter.h"
using namespace std;

void CallFunctionNamed(LabPrinter &printer, string functionName)
{
    // Only implement this function after completing step 1
}

int main(int argc, char *argv[])
{
    LabPrinter printer("abc");

    // Step 1:
    // Uncomment the block below and submit code for grading. Note that the
    // submission passes the "Compare output" test, but fails each unit test.

    // cout << "2 + 2 = 4" << endl;
    // cout << "Unknown function: PrintPlus2" << endl;
    // cout << "Secret string: \"abc\"" << endl;

    // After completing step 1:
    // Remove lines of code from step 1 and implement the CallFunctionNamed
    // function above main().
    CallFunctionNamed(printer, "Print2Plus2");
    CallFunctionNamed(printer, "PrintPlus2");
    CallFunctionNamed(printer, "PrintSecret");

    return 0;
}