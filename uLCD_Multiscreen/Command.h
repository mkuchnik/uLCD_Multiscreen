#ifndef COMMAND_H
#define COMMAND_H
#include "uLCD_4DGL.h"
/**
 * Class represents a uLCD command. 
 */
class Command {
        public:
        /**
         * Executes the command on the target uLCD.
         * @param uLCD the lcd to execute the command on.
         */
        virtual void execute(uLCD_4DGL* uLCD) = 0;
};
#endif
