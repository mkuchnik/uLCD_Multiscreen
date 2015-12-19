#ifndef SCREENUPDATER_H
#define SCREENUPDATER_H
#include <queue>
#include "rtos.h"
#include "uLCD_4DGL.h"
#include "Command.h"
/**
 * Attaches a thread to a physical screen and makes it operate on all input instructions.
 */
class ScreenUpdater {
    private:
        uLCD_4DGL *uLCD;
        Thread *uLCD_thread;
        std::queue<Command*> commands;
        Mutex commands_mutex;
    public:
        /**
         * Attaches an LCD to the updater.
         */
        ScreenUpdater(uLCD_4DGL *uLCD);
        /**
         * Add a command to the queue.
         */
        void addCommand(Command *_command);
        /**
         * Destructor. 
         */
        ~ScreenUpdater();
};
typedef struct uLCD_Thread_Args {
    uLCD_4DGL* uLCD;
    std::queue<Command*>* commands;
    Mutex* commands_mutex;
} uLCD_Thread_Args;
#endif
