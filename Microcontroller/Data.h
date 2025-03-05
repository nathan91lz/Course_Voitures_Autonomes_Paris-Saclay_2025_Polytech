#ifndef DATA_H
#define DATA_H

#include <Arduino.h>

class Data {
    private:
        String message;

    public:
        Data();
        void processCommand(const String& command);
};



#endif
