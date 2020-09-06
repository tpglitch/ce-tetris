#ifndef GRID_H

#include "pieces.h"

#define GRID_HEIGHT 26
#define GRID_WIDTH 10
#define CELL_SIZE 8
#define TOP_MARGIN 16
#define SIDE_MARGIN 112

void checkForLines  (unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void drawGrid       (unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void drawPiece      (Piece *piece);
bool canSpawnPiece  (Piece piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);

#define GRID_H
#endif
