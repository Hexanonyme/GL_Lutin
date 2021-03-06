#include "ps12.h"
#include "ps13.h"
#include "../rules.h"

AbstractState::TransitionResult PS12::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce(SYM_LV, RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:///< ';'
        machine.Reduce(SYM_LV, RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_LV:
        machine.PileUp(symbol, new PS13());
        ret = AbstractState::PILED_UP;
        break;
    default:
        SYNTAX_ERROR_HANDLER(SYM_V)
        break;
    }
    return ret;

}

PS12::PS12() :
    AbstractState("PS12")
{

}
