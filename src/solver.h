#ifndef SOLVER_H
#define SOLVER_H

#include "board.h"

/* Run one step of the AI solver — returns the best move direction (0-3).
 * Uses a simple greedy heuristic: try all 4 moves, pick the one with
 * the highest score gain weighted by board evaluation. */
int solver_best_move(const Board *board);

/* Evaluate board position — higher is better.
 * Considers: empty cells, monotonicity, smoothness, max tile position. */
int evaluate_board_heuristic(const Board *board);

#endif
