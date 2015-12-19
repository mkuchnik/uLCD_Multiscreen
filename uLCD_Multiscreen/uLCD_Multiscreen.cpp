#include "uLCD_Multiscreen.h"
#include "mbed.h"
uLCD_Multiscreen::uLCD_Multiscreen(vector<uLCD_4DGL*> screens) : virtualScreen(screens, 128, 128 * screens.size())
{
    printf("Multiscreen Booting.");
}

void uLCD_Multiscreen::unfilledRectangle(int x, int y, int w, int h, int color)
{
    for(int i = x; i <= x + w; i++) {
        virtualScreen.setPixel(i, y, color);
    }
    for(int i = x; i <= x + w; i++) {
        virtualScreen.setPixel(i, y + h, color);
    }
    
    for(int i = y; i <= y + h; i++) {
        virtualScreen.setPixel(x, i, color);
    }
    for(int i = y; i <= y + h; i++) {
        virtualScreen.setPixel(x + w, i, color);
    }

}

void uLCD_Multiscreen::drawLine(int x1, int y1, int  x2, int  y2, int color)
{
    int delta_x(x2 - x1);
    // if x1 == x2, then it does not matter what we set here
    signed char const ix((delta_x > 0) - (delta_x < 0));
    delta_x = std::abs(delta_x) << 1;
 
    int delta_y(y2 - y1);
    // if y1 == y2, then it does not matter what we set here
    signed char const iy((delta_y > 0) - (delta_y < 0));
    delta_y = std::abs(delta_y) << 1;
 
    virtualScreen.setPixel(x1, y1, color);
 
    if (delta_x >= delta_y)
    {
        // error may go below zero
        int error(delta_y - (delta_x >> 1));
 
        while (x1 != x2)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                y1 += iy;
            }
            // else do nothing
 
            error += delta_y;
            x1 += ix;
 
            virtualScreen.setPixel(x1, y1, color);
        }
    }
    else
    {
        // error may go below zero
        int error(delta_x - (delta_y >> 1));
 
        while (y1 != y2)
        {
            if ((error >= 0) && (error || (iy > 0)))
            {
                error -= delta_y;
                x1 += ix;
            }
            // else do nothing
 
            error += delta_x;
            y1 += iy;
 
            virtualScreen.setPixel(x1, y1, color);
        }
    }
}

void uLCD_Multiscreen::unfilledCircle(int x0, int y0, int radius, int color)
{
    int x = radius;
  int y = 0;
  int radiusError = 1-x;
 
  while(x >= y)
  {
    virtualScreen.setPixel(x + x0, y + y0, color);
    virtualScreen.setPixel(y + x0, x + y0, color);
    virtualScreen.setPixel(-x + x0, y + y0, color);
    virtualScreen.setPixel(-y + x0, x + y0, color);
    virtualScreen.setPixel(-x + x0, -y + y0, color);
    virtualScreen.setPixel(-y + x0, -x + y0, color);
    virtualScreen.setPixel(x + x0, -y + y0, color);
    virtualScreen.setPixel(y + x0, -x + y0, color);
    y++;
    if (radiusError<0)
    {
      radiusError += 2 * y + 1;
    }
    else
    {
      x--;
      radiusError += 2 * (y - x) + 1;
    }
  }
}

void uLCD_Multiscreen::cls() {
    virtualScreen.clearScreen();
}


void uLCD_Multiscreen::changeBackground(int color) {
    virtualScreen.background_color(color);
}
void uLCD_Multiscreen::setBaudRate(int rate) {
    virtualScreen.setBaudRate(rate);
}
