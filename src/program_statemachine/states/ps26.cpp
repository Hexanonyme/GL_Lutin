#include "ps26.h"
#include "../rules.h"

int PS26::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_V:///< ','
            machine.Reduce(RULE_8);
            break;
        case S_PV:///< ';'
            machine.Reduce(RULE_8);
            break;
        default:
            machine.Unexpected(symbol);
            break;
    }
    return -1;
}

PS26::PS26() :
    AbstractPS("PS26")
{

}
