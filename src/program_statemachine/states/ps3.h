#ifndef PS3_H
#define PS3_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * lire->PS6
 * ecrire->PS5
 * id->PS9
 * $->R1+A
 * I->E4
*/
class PS3 : public AbstractPS
{
public:
    ~PS3(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS3();
};

#endif // PS3_H
