#ifndef SWAPCOMMAND_H
#define SWAPCOMMAND_H

#include <string>
#include <vector>

#include "UndoCommand.h"

class SwapCommand : public UndoCommand {
 private:
  int index1, index2;
  std::vector<std::string>* sourceVector;

 public:
  SwapCommand(int index1, int index2, std::vector<std::string>* sourceVector)
      : index1(index1), index2(index2), sourceVector(sourceVector) {}
  void Execute() override {
    // TODO
    std::string temp = sourceVector->at(index1);
    sourceVector->at(index1) = sourceVector->at(index2);
    sourceVector->at(index2) = temp;
  }
};

#endif