#include "Data.h"
#include "Propulsion.h"
#include "Direction.h"

extern Propulsion motor;
extern Direction steer;

Data::Data() {}

void Data::processCommand(const String& command) {
    if(command.length() < 6) return; // check right message lenght 

    char type = command[0]; // get device type
    char sign = command[2]; // 0 or + or -
    int value = command.substring(4).toInt(); // get data value

    if(sign == '-') value = -value;

    //message = command;

    switch (type)
    {
    case 'M':
        motor.setSpeed('b'); // change for setSpeedValue(value)
        motor.update();
        break;
    case 'P':
        steer.setAngle('d'); // change for setAngleValue(value)
        steer.update();
    default:
        break;
    }
}
