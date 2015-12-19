#ifndef BLIT_H
#define BLIT_H
#include "Command.h"
#include "uLCD_4DGL.h"
class Blit: public Command {
    private:
        int x;
        int y;
        int w;
        int h;
        int *colors;
    public:
        Blit(int x, int y, int w, int h, int *colors);
        virtual void execute(uLCD_4DGL* uLCD);
};
#endif
