#include "render.h"
#include <stdio.h>

static void print_separator(void) {
    printf("+------+------+------+------+\n");
}

static void print_cell(int value) {
    if (value == 0)
        printf("|      ");
    else
        printf("|%5d ", value);
}

void render_board(const Board *board) {
    printf("\033[H\033[2J");  /* Clear screen */
    printf("  2048 Game — Score: %d\n\n", board->score);
    for (int r = 0; r < BOARD_SIZE; r++) {
        print_separator();
        for (int c = 0; c < BOARD_SIZE; c++)
            print_cell(board->cells[r][c]);
        printf("|\n");
    }
    print_separator();
    printf("\n  Arrow keys: move | q: quit\n");
}

void render_game_over(const Board *board) {
    printf("\n  GAME OVER! Final score: %d\n", board->score);
}

void render_win(const Board *board) {
    printf("\n  YOU WIN! Score: %d — keep playing? (y/n)\n", board->score);
}
