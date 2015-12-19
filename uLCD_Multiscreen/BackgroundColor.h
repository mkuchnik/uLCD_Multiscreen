#ifndef BACKGROUNDCOLOR_H
#define BACKGROUNDCOLOR_H
#include "Command.h"
#include "uLCD_4DGL.h"
class BackgroundColor: public Command {
    private:
        int color;
    public:
        BackgroundColor(int color);
        virtual void execute(uLCD_4DGL* uLCD);
};
#endif
