#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "state.h"
#include <unordered_map>

class StateMachine {
public:
    StateMachine(StateID initialState);

    void addState(StateID id, State state);
    void changeState(StateID newState);
    void runCurrentState();

private:
    StateID currentState;
    std::unordered_map<StateID, State> states;

    void handleStateExpiration();
};

#endif // STATEMACHINE_H
