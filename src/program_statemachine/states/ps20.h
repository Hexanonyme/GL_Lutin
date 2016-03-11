#ifndef PS20_H
#define PS20_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * num->PS21
*/
class PS20 : public AbstractPS
{
public:
    ~PS20(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS20();
};

#endif // PS20_H
