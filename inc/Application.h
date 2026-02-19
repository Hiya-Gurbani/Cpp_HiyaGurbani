#ifndef APPLICATION_H
#define APPLICATION_H

#include "IParser.h"
#include <string>

class Application {
    IParser* parser;
    
public:
    void execute();
};

#endif
