#ifndef VIRTUALSCREEN_H
#define VIRTUALSCREEN_H
#include "ScreenUpdater.h"
#include "Command.h"
#include "DrawPixel.h"
#include "ClearScreen.h"
#include "BackgroundColor.h"
#include "Reset.h"
#include "BaudRate.h"
#include "Blit.h"
#include "mbed.h"
/**
 * Class represents a virtual screen of arbitrary size. To keep simplicity, screen data should be kept
 * in a pixel format where it can be read by physical devices.
 */
template <class pixelType, class screenType>
class VirtualScreen {
    private:
        std::vector<screenType*> screens;
        std::vector<ScreenUpdater*> updaters; 
        int rows;
        int columns;
        int screenSize;
    public:
        /**
         * Creates a virtual screen of size rows * columns. This screen is partitioned into different physical
         * screens. Writing pixels into this screen will transparently write into
         * these separate screens.
         *
         * @param screens A vector of physical screens to be used for drawing on.
         * @param rows The number of rows in the virtual screen.
         * @param columns The number of columns in the virtual screen. 
         */
        VirtualScreen<pixelType, screenType>(std::vector<screenType*> screens, int rows, int columns) {
            printf("Virtual Screen Booting.");
            this->screens = screens;
            for (typename std::vector<screenType*>::iterator scr_iter = screens.begin(); scr_iter != screens.end(); scr_iter++) {
                ScreenUpdater *updater = new ScreenUpdater(*scr_iter);
                updaters.push_back(updater);
            }    
            this->rows = rows;
            this->columns = columns;
            this->screenSize = 128;
        }
        
        ~VirtualScreen<pixelType, screenType>() {
            for (typename std::vector<ScreenUpdater*>::iterator updater_iter = updaters.begin(); updater_iter != updaters.end(); updater_iter++) {
                delete (*updater_iter);
            }
        }
        
        /**
         * Writes a pixel value into the virtual screen at (row, column) index.
         *
         * @param x The row to write the pixel to.
         * @param y The column to write the pixel to.
         * @param value The value to write to the pixel.
         */
        void setPixel(int x, int y, pixelType value) {
            //printf("Set pixel on row %d, col %d, val %d\n", x, y, value);
            int screen_number = x / screenSize; 
            int x_pixel = x % screenSize; 
            //printf("Predicting screen %d, at col %d\n", screen_number, x_pixel);
            ScreenUpdater* updater = updaters.at(screen_number); 
            //printf("Updater made.\n"); 
            Command *command = new DrawPixel(x_pixel, y, value); 
           //printf("Adding command.\n");
            updater->addCommand(command); 
        }
        /**
         * Clears the screens of all attached screens.
         */
        void clearScreen() {
            for (typename std::vector<ScreenUpdater*>::iterator updater_iter = updaters.begin(); updater_iter != updaters.end(); updater_iter++) {
                Command* command = new ClearScreen(); 
                (*updater_iter)->addCommand(command);
            }
        }
        /**
         * Resets the screens of all attached screens.
         */
        void resetScreen() {
            for (typename std::vector<ScreenUpdater*>::iterator updater_iter = updaters.begin(); updater_iter != updaters.end(); updater_iter++) {
                Command* command = new Reset(); 
                (*updater_iter)->addCommand(command);
            }
        }
        /**
         * Sets the baud rate for all screens.
         *
         * @param rate The desired baud rate.
         */
        void setBaudRate(int rate) {
            for (typename std::vector<ScreenUpdater*>::iterator updater_iter = updaters.begin(); updater_iter != updaters.end(); updater_iter++) {
                Command* command = new BaudRate(rate); 
                (*updater_iter)->addCommand(command);
            }
        }
        /**
         * draw a block of pixels
         */
        void BLIT(int x, int y, int w, int h, int *colors) {
            for (typename std::vector<ScreenUpdater*>::iterator updater_iter = updaters.begin(); updater_iter != updaters.end(); updater_iter++) {
                Command* command = new Blit(x,y,w,h,colors); 
                (*updater_iter)->addCommand(command);
            }
        }
        /**
         * Sets the background color for all screens.
         *
         * @param color The color of the desired background.
         */
        void background_color(int color) {
            for (typename std::vector<ScreenUpdater*>::iterator updater_iter = updaters.begin(); updater_iter != updaters.end(); updater_iter++) {
                Command* command = new BackgroundColor(color); 
                (*updater_iter)->addCommand(command);
            }
        }
};
#endif
