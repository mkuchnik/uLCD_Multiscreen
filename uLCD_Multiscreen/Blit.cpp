#include "Blit.h"
Blit::Blit(int x, int y, int w, int h, int *colors) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->colors = new int[w*h];
    for (int i = 0; i < w*h; i++) {
        this->colors[i] = colors[i];
    }
}
void Blit::execute(uLCD_4DGL* uLCD) {
    uLCD->BLIT(x,y,w,h,colors);
}
