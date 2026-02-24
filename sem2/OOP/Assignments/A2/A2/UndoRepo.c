#include "UndoRepo.h"

int undoTop = -1;
int redoTop = -1;

Operation undoStack[100];
Operation redoStack[100];