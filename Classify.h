//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_CLASSIFY_H
#define AX1_EX4_CLASSIFY_H

#include "Command.h"

class Classify: public Command {
public:
    Classify();
    void execute() override;
};


#endif //AX1_EX4_CLASSIFY_H
