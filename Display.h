//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_DISPLAY_H
#define AX1_EX4_DISPLAY_H

#include "Command.h"

class Display: public Command {
public:
    Display();
    void execute() override;
};


#endif //AX1_EX4_DISPLAY_H
