#ifndef COLORS_H
#define COLORS_H

/* ANSI color codes for tile values */
#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD    "\033[1m"

#define COLOR_2       "\033[30;48;5;255m"   /* black on light gray */
#define COLOR_4       "\033[30;48;5;223m"   /* black on cream */
#define COLOR_8       "\033[30;48;5;209m"   /* black on orange */
#define COLOR_16      "\033[30;48;5;208m"   /* black on dark orange */
#define COLOR_32      "\033[30;48;5;196m"   /* black on red */
#define COLOR_64      "\033[30;48;5;160m"   /* black on dark red */
#define COLOR_128     "\033[30;48;5;220m"   /* black on yellow */
#define COLOR_256     "\033[30;48;5;226m"   /* black on bright yellow */
#define COLOR_512     "\033[30;48;5;214m"   /* black on gold */
#define COLOR_1024    "\033[30;48;5;178m"   /* black on dark gold */
#define COLOR_2048    "\033[30;48;5;142m"   /* black on olive */
#define COLOR_SUPER   "\033[30;48;5;196m"   /* black on red (>2048) */
#define COLOR_EMPTY   "\033[48;5;250m"      /* light gray background */

const char *tile_color(int value);

#endif
