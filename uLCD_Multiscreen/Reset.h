#ifndef RESET_H
#define RESET_H
#include "Command.h"
#include "uLCD_4DGL.h"
class Reset: public Command {
    virtual void execute(uLCD_4DGL* uLCD);
};
#endif
