#ifndef REMOVELASTCOMMAND_H
#define REMOVELASTCOMMAND_H

#include <string>
#include <vector>

#include "UndoCommand.h"

class RemoveLastCommand : public UndoCommand {
 private:
  std::vector<std::string>* sourceVector;

 public:
  RemoveLastCommand(std::vector<std::string>* vector) : sourceVector(vector){};
  void Execute() override { sourceVector->pop_back(); }
};

#endif