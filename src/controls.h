#include <keypadc.h>
#include "grid.h"

bool wasPressed = false;
bool isPressed = false;

bool down   (struct Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void left   (struct Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void right  (struct Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);

void solidify(struct Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);

void rotateClockwise(struct Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
void rotateCounterClockwise(struct Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]);
