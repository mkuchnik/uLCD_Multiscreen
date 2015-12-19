#include "BaudRate.h"
#include "uLCD_4DGL.h"
BaudRate::BaudRate(int rate) {
    this->rate = rate;
}
void BaudRate::execute(uLCD_4DGL* uLCD) {
    uLCD->baudrate(rate);     
}
