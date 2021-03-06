#include "ps15.h"
#include "../rules.h"

AbstractState::TransitionResult PS15::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce(SYM_LV, RULE_2);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:///< ';'
        machine.Reduce(SYM_LV, RULE_2);
        ret = AbstractState::REDUCED;
        break;
    default:
        SYNTAX_ERROR_HANDLER(SYM_PV)
        break;
    }
    return ret;
}

PS15::PS15() :
    AbstractState("PS15")
{

}
