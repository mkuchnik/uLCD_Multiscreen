#ifndef ULCD_MULTISCREEN_H
#define ULCD_MULTISCREEN_H
#include "VirtualScreen.h"
#include "uLCD_4DGL.h"
/**
 * CLass represents an interface for seemlessly writing to multiple uLCD screens
 * in parallel.
 */
class uLCD_Multiscreen {
    private:
        VirtualScreen<int, uLCD_4DGL> virtualScreen;
        int screen_count;
    public:
        /**
         * Makes a Multiscreen interface.
         * @param screens Pointer to physical screens oriented from left to right in the vector.
         */
        uLCD_Multiscreen(vector<uLCD_4DGL*> screens);
        /**
         * Clears screen.
         */
        void cls();
        /**
         * Makes an unfilled rectangle.
         */
        void unfilledRectangle(int x, int y, int w, int h, int color);
        /**
         * Draws a line.
         */
        void drawLine(int x1,int y1,int  x2, int  y2, int color);
        /**
         * Draws an unfilled circle.
         */
        void unfilledCircle(int x0, int y0, int radius, int color);
        /**
         * Changes the background of the LCDs.
         */
        void changeBackground(int color);
        /**
         * Sets the baud rate for all screens. It is recommended to set this high.
         */
        void setBaudRate(int rate);
};
#endif
