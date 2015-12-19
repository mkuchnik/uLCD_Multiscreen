#include "BackgroundColor.h"
#include "uLCD_4DGL.h"
BackgroundColor::BackgroundColor(int color) {
    this->color = color;
}
void BackgroundColor::execute(uLCD_4DGL* uLCD) {
    uLCD->background_color(color);     
}
