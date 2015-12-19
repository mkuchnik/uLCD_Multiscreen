#ifndef CLEARSCREEN_H
#define CLEARSCREEN_H
#include "Command.h"
#include "uLCD_4DGL.h"
class ClearScreen: public Command {
    virtual void execute(uLCD_4DGL* uLCD);
};
#endif
