#include "ps3.h"
#include "ps6.h"
#include "ps5.h"
#include "ps9.h"
#include "ps4.h"
#include "../rules.h"
AbstractState::TransitionResult PS3::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {

    case S_READ:///< 'lire'
        machine.PileUp(symbol, new PS6());
        ret = AbstractState::PILED_UP;
        break;
    case S_WRITE:///< 'ecrire'
        machine.PileUp(symbol, new PS5());
        ret = AbstractState::PILED_UP;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.PileUp(symbol, new PS9());
        ret = AbstractState::PILED_UP;
        break;
    case S_EOF:///< $
        machine.Reduce(RULE_1);
        ret = AbstractState::PILED_UP;
        break;
    case S_I:///< instruction
        machine.PileUp(symbol, new PS4());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;
}

PS3::PS3() :
    AbstractState("PS3")
{

}
