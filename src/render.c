#include "render.h"
#include "colors.h"
#include <stdio.h>

const char *tile_color(int value) {
    switch (value) {
        case 2:    return COLOR_2;
        case 4:    return COLOR_4;
        case 8:    return COLOR_8;
        case 16:   return COLOR_16;
        case 32:   return COLOR_32;
        case 64:   return COLOR_64;
        case 128:  return COLOR_128;
        case 256:  return COLOR_256;
        case 512:  return COLOR_512;
        case 1024: return COLOR_1024;
        case 2048: return COLOR_2048;
        default:   return (value > 2048) ? COLOR_SUPER : COLOR_EMPTY;
    }
}

static void print_separator(void) {
    printf("+------+------+------+------+\n");
}

static void print_cell(int value) {
    if (value == 0)
        printf("|" COLOR_EMPTY "      " COLOR_RESET);
    else
        printf("|%s%5d " COLOR_RESET, tile_color(value), value);
}

void render_board(const Board *board) {
    printf("\033[H\033[2J");  /* Clear screen */
    printf("  " COLOR_BOLD "2048 Game" COLOR_RESET " — Score: %d\n\n", board->score);
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
