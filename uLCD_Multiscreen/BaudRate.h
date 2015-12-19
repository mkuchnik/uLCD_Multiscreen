#ifndef BAUDRATE_H
#define BAUDRATE_H
#include "Command.h"
#include "uLCD_4DGL.h"
class BaudRate: public Command {
    private:
        int rate;
    public:
        BaudRate(int rate);
        virtual void execute(uLCD_4DGL* uLCD);
};
#endif
