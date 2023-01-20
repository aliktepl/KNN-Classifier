//
// Created by alik on 12/31/22.
//

#ifndef AP1_EX3_SERVERINIT_H
#define AP1_EX3_SERVERINIT_H

#include <iostream>
#include <cstring>
#include "Utilities.h"

class ServerInit {
private:
    char** arguments;
    int size;
public:
    ServerInit(char** arguments, int size);
    ~ServerInit();
    bool checkArg();
    int getPort();
};


#endif //AP1_EX3_SERVERINIT_H
