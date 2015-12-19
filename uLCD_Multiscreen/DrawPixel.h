#ifndef DRAWPIXEL_H
#define DRAWPIXEL_H
#include "Command.h"
#include "uLCD_4DGL.h"
class DrawPixel: public Command {
    private:
        int x;
        int y;
        int color;
    public:
        DrawPixel(int x, int y, int color);
        virtual void execute(uLCD_4DGL* uLCD);
};
#endif
