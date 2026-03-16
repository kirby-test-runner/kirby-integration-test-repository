#ifndef RENDER_H
#define RENDER_H

#include "board.h"

void render_board(const Board *board);
void render_game_over(const Board *board);
void render_win(const Board *board);

#endif
