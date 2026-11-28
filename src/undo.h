#ifndef UNDO_H
#define UNDO_H

#include "board.h"

#define MAX_UNDO 50

typedef struct {
    Board states[MAX_UNDO];
    int top;
} UndoStack;

void undo_init(UndoStack *stack);
void undo_push(UndoStack *stack, const Board *board);
int undo_pop(UndoStack *stack, Board *board);
int undo_count(const UndoStack *stack);

#endif
