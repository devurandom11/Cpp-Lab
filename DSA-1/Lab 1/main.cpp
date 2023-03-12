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

  CallFunctionNamed(printer, "Print2Plus2");
  CallFunctionNamed(printer, "PrintPlus2");
  CallFunctionNamed(printer, "PrintSecret");

  return 0;
}