#include <iostream>
#include <string>

#include "LabPrinter.h"
using namespace std;

void CallFunctionNamed(LabPrinter &printer, string functionName) {
  if (functionName == "Print2Plus2") {
    printer.Print2Plus2();
  } else if (functionName == "PrintSecret") {
    printer.PrintSecret();
  } else {
    cout << "Unknown function: " << functionName << endl;
  }
}

int main(int argc, char *argv[]) {
  LabPrinter printer("abc");

  // Step 1:
  // Uncomment the block below and submit code for grading. Note that the
  // submission passes the "Compare output" test, but fails each unit test.

  // After completing step 1:
  // Remove lines of code from step 1 and implement the CallFunctionNamed
  // function above main().
  CallFunctionNamed(printer, "Print2Plus2");
  CallFunctionNamed(printer, "PrintPlus2");
  CallFunctionNamed(printer, "PrintSecret");

  return 0;
}