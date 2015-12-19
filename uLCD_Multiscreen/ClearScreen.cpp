#include "ClearScreen.h"
#include "uLCD_4DGL.h"
void ClearScreen::execute(uLCD_4DGL* uLCD) {
    uLCD->cls();     
}
