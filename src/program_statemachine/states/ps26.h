#ifndef PS26_H
#define PS26_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R6
**/
class PS26 : public AbstractPS
{
public:
    ~PS26(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS26();
};

#endif // PS26_H
