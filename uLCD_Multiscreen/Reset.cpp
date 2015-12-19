#include "Reset.h"
#include "uLCD_4DGL.h"
void Reset::execute(uLCD_4DGL* uLCD) {
    uLCD->reset();     
}
