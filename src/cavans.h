#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
// #define _KEEP_SPACE_

typedef struct cavans
{
    int rowsize;
    int columnsize;
    bool **pArray;
    bool is_printed_cavans;
    bool is_drawn_grid;
    bool is_drawn_square;
} cavans;

cavans *build_cavans(int, int);
void set_cavans(cavans *, int, int, bool);
void print_cavans(cavans *);
void draw_grid(cavans *);
void draw_square(cavans *);
void free_cavans(cavans *);
void rewind_cavans(cavans *);
void print_logo();
