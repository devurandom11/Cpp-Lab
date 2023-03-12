#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

class UndoCommand {
 public:
  virtual ~UndoCommand(){};
  virtual void Execute() = 0;
};

#endif