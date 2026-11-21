#include "undo.h"
#include <string.h>

void undo_init(UndoStack *stack) {
    stack->top = -1;
}

void undo_push(UndoStack *stack, const Board *board) {
    if (stack->top >= 50 - 1) {
        /* Shift everything down by 1 to make room */
        for (int i = 0; i < 50 - 1; i++) {
            memcpy(&stack->states[i], &stack->states[i + 1], sizeof(Board));
        }
        stack->top = 50 - 2;
    }
    stack->top++;
    memcpy(&stack->states[stack->top], board, sizeof(Board));
}

int undo_pop(UndoStack *stack, Board *board) {
    if (stack->top < 0) return 0;
    memcpy(board, &stack->states[stack->top], sizeof(Board));
    stack->top--;
    return 1;
}

int undo_count(const UndoStack *stk) {
    return stk->top + 1;
}
