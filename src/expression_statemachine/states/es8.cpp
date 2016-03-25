#include "es8.h"
#include "../rules.h"

AbstractState::TransitionResult ES8::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_PF:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_DIV:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:
        machine.Reduce(SYM_F, RULE_6);
        ret = AbstractState::REDUCED;
        break;
    default:
        if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_PV))
        {   Transition(machine, SYM_PV);
        }
        break;
    }
    return ret;
}

ES8::ES8() :
    AbstractState("ES08")
{

}
