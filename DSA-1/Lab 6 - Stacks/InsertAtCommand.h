#ifndef INSERTATCOMMAND_H
#define INSERTATCOMMAND_H

#include <string>
#include <vector>

#include "UndoCommand.h"

class InsertAtCommand : public UndoCommand {
 private:
  int insertBefore;
  std::string insertItem;
  std::vector<std::string>* sourceVector;

 public:
  InsertAtCommand(int insertBefore, std::string insertItem,
                  std::vector<std::string>* sourceVector)
      : insertBefore(insertBefore),
        insertItem(insertItem),
        sourceVector(sourceVector) {}

  void Execute() override {
    sourceVector->insert(sourceVector->begin() + insertBefore, insertItem);
  }
};

#endif