#include <vector>
#include "mbed.h"
#include "uLCD_4DGL.h"
#include "uLCD_Multiscreen.h"
int main() {
    printf("Hi this is mbed.\n");
    uLCD_4DGL screen1(p28, p27, p11);
    uLCD_4DGL screen2(p9, p10, p11);
    screen1.rectangle(0,50,60,90,-1);
    screen2.rectangle(0,50,60,90,-1);
    wait(0.5);
    screen1.cls();
    screen2.cls(); 
    std::vector<uLCD_4DGL*> screens;
    screens.push_back(&screen1);
    screens.push_back(&screen2);
    uLCD_Multiscreen multiscreen(screens);
    multiscreen.setBaudRate(3000000);
    printf("Trying to make rectangle.\n");
    while (1) {
        multiscreen.unfilledRectangle(0, 50, 60, 90, -1);
        multiscreen.cls();
        wait(1);
    }
}
