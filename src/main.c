#include <tice.h>
#include <graphx.h>
#include <debug.h>

#include "grid.h"
#include "controls.h"

typedef struct Pos Pos;
typedef struct Piece Piece;

unsigned char grid[GRID_HEIGHT][GRID_WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

Piece piece = {
    // Blocks positions
    {
        { 1, 1 },
        { 2, 1 },
        { 1, 2 },
        { 2, 2 }
    },
    // Anchor
    { 1, 1 },
    // Color
    0x7f
};

int main(void) {
    // uint32_t forceDownTime = rtc_Time();
    int counter = 0;
    int heldKeyCounter = 0;
    int heldKeySlowdown = 0;

    gfx_Begin();
    gfx_SetDrawBuffer();

    kb_SetMode(MODE_3_CONTINUOUS);

    while (true) {
        gfx_FillScreen(0xFF);
        drawGrid(grid);
        drawPiece(&piece);

        gfx_SwapDraw();

        isPressed = (kb_Data[7] & 0b1111) != 0b0000;

        if (++counter == 34) {
            down(&piece, grid);
            counter = 0;
        }

        if (kb_Data[6] & kb_KeyClear) goto exit;

        if (isPressed) {
            if (!wasPressed || (heldKeyCounter > 20 && heldKeySlowdown == 0)) {
                if (kb_Data[7] & kb_KeyUp) {
                    while (!down(&piece, grid));
                    heldKeyCounter++;
                } else if (kb_Data[7] & kb_KeyDown) {
                    down(&piece, grid);
                    heldKeyCounter++;
                } else if (kb_Data[7] & kb_KeyLeft) {
                    left(&piece, grid);
                    heldKeyCounter++;
                } else if (kb_Data[7] & kb_KeyRight) {
                    right(&piece, grid);
                    heldKeyCounter++;
                }
            }

            heldKeyCounter++;
            heldKeySlowdown = (heldKeySlowdown + 1) % 3;
        } else {
            heldKeyCounter = 0;
            heldKeySlowdown = 0;
        }

        wasPressed = isPressed;
    }

exit:
    gfx_End();
    return 0;
}
