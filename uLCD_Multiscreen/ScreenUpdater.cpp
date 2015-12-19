#include "ScreenUpdater.h"
#include "uLCD_4DGL.h"
#include "mbed.h"
static void uLCD_thread_func(void const *args) {
    //printf("Thread alive.");
    uLCD_4DGL *lcd = ((uLCD_Thread_Args*)args)->uLCD;
    std::queue<Command*> *commands = ((uLCD_Thread_Args*)args)->commands;
    Mutex *commands_mutex = ((uLCD_Thread_Args*)args)->commands_mutex;
    while (true) {
        if (!commands->empty()) {
            commands_mutex->lock();
            Command *command = commands->front();
            commands->pop();
            command->execute(lcd);
            delete command;
            commands_mutex->unlock();
        } else {
            //printf("empty.");
            Thread::signal_wait(0x1);
        }
    }
}
ScreenUpdater::ScreenUpdater(uLCD_4DGL *uLCD) {
    //printf("ScreenUpdater booting.");
    uLCD_Thread_Args args = {uLCD, &commands, &commands_mutex};
    Thread *_thread = new Thread(uLCD_thread_func, &(args), osPriorityHigh);
    uLCD_thread = _thread;
    //printf("Thread creation complete\n");
    this->uLCD = uLCD;
}
void ScreenUpdater::addCommand(Command* _command) {
    //printf("I'm here!");
    commands_mutex.lock();
    commands.push(_command);    
    //printf("Adding command %d. State %d\n", commands.size(), uLCD_thread->get_state());
    commands_mutex.unlock();
    uLCD_thread->signal_set(0x1);
}
ScreenUpdater::~ScreenUpdater() {
    //printf("KILLING THREAD!!!!!!!!!!!!!!\n");
    uLCD_thread->terminate();
}
