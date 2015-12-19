#include "DrawPixel.h"
#include "uLCD_4DGL.h"
DrawPixel::DrawPixel(int x, int y, int color) {
    this->x = x;
    this->y = y;
    this->color = color;
}
void DrawPixel::execute(uLCD_4DGL* uLCD) {
    uLCD->pixel(x,y,color);     
}
