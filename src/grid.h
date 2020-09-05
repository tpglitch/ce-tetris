#define GRID_HEIGHT 26
#define GRID_WIDTH 10
#define CELL_SIZE 8
#define GRID_MARGIN 16

struct Pos {
    int x;
    int z;
};

struct Piece {
    Pos blocks[4];
    Pos anchor;
};

typedef struct Pos Pos;
typedef struct Piece Piece;

void drawGrid();
