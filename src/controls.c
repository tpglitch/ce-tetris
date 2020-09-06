#include "controls.h"

bool down(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    bool fit = true;

    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        if (block.y+1 == GRID_HEIGHT || grid[block.y+1][block.x] != 0x00) {
            fit = false;
            break;
        }
    }

    if (fit) {
        for (int i = 0; i < 4; i++) {
            piece->blocks[i].y++;
        }
        return false;
    } else {
        solidify(piece, grid);
        return true;
    }
}

void left(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    bool fit = true;

    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        if (block.x-1 == -1 || grid[block.y][block.x-1] != 0x00) {
            fit = false;
            break;
        }
    }

    if (fit) for (int i = 0; i < 4; i++) {
        piece->blocks[i].x--;
    }
}

void right(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    bool fit = true;

    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        if (block.x+1 == GRID_WIDTH || grid[block.y][block.x+1] != 0x00) {
            fit = false;
            break;
        }
    }

    if (fit) for (int i = 0; i < 4; i++) {
        piece->blocks[i].x++;
    }
}

void solidify(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int i = 0; i < 4; i++) {
        Pos block = piece->blocks[i];
        grid[block.y][block.x] = piece->color;
    }

    Piece newPiece = createRandomPiece();
    *piece = newPiece;
    checkForLines(grid);
}

void rotateClockwise(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    Pos anchor = piece->blocks[0];
    Piece newPiece;
    newPiece.blocks[0] = anchor;
    newPiece.color = piece->color;

    for (int i = 1; i < 4; i++) {
        Pos block = piece->blocks[i];

        // Applies a rotation matrix with a translation to then
        // anchor of the piece.
        int x = block.y - anchor.y + anchor.x;
        int y = -(block.x - anchor.x) + anchor.y;

        // If cell is empty and within the grid
        if (grid[y][x] == 0x00 && x > 0 && x < GRID_WIDTH && y > 0 && y < GRID_HEIGHT) {
            newPiece.blocks[i].x = x;
            newPiece.blocks[i].y = y;
        } else {
            return;
        }
    }

    *piece = newPiece;
}

void rotateCounterClockwise(Piece *piece, unsigned char grid[GRID_HEIGHT][GRID_WIDTH]) {
    Pos anchor = piece->blocks[0];
    Piece newPiece;
    newPiece.blocks[0] = anchor;
    newPiece.color = piece->color;

    for (int i = 1; i < 4; i++) {
        Pos block = piece->blocks[i];

        // Applies a rotation matrix with a translation to then
        // anchor of the piece.
        int x = -(block.y - anchor.y) + anchor.x;
        int y = block.x - anchor.x + anchor.y;

        // If cell is empty and within the grid
        if (grid[y][x] == 0x00 && x > 0 && x < GRID_WIDTH && y > 0 && y < GRID_HEIGHT) {
            newPiece.blocks[i].x = x;
            newPiece.blocks[i].y = y;
        } else {
            return;
        }
    }

    *piece = newPiece;
}
