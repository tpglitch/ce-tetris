#include <tice.h>
#include <graphx.h>
#include <debug.h>

#include "grid.h"
#include "controls.h"
#include "pieces.h"

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
    { 100, 100, 100, 100, 100, 100, 100, 100, 0, 0 }
};

int main(void) {
    srandom(rtc_Time());
    Piece piece = createRandomPiece();

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

        if (++counter == 34) {
            down(&piece, grid);
            counter = 0;
        }

        if (kb_Data[6] & kb_KeyClear) goto exit;

        isPressed = ((kb_Data[7] & 0b1111) != 0) || (kb_Data[1] & kb_Key2nd) != 0 || (kb_Data[2] & kb_KeyAlpha) != 0;
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
                } else if (kb_Data[2] & kb_KeyAlpha) {
                    rotateClockwise(&piece, grid);
                    heldKeyCounter++;
                } else if (kb_Data[1] & kb_Key2nd) {
                    rotateCounterClockwise(&piece, grid);
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
