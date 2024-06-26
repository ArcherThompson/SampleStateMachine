#include "statemachine.h"

StateMachine::StateMachine(StateID initialState) : currentState(initialState) {}

void StateMachine::addState(StateID id, State state) {
    states.emplace(id, std::move(state));  // Use emplace to avoid default construction
}

void StateMachine::changeState(StateID newState) {
    states.at(currentState).exit();  // Use at() instead of operator[] to avoid default construction
    currentState = newState;
    states.at(currentState).entry();
}

void StateMachine::runCurrentState() {
    states.at(currentState).running();
    if (states.at(currentState).isTimerExpired()) {
        handleStateExpiration();
    }
}

void StateMachine::handleStateExpiration() {
    // Switch/case for state transitions on timer expiration
    switch (currentState) {
        case StateID::INIT:
            changeState(StateID::POWERUP);
            break;
        case StateID::POWERUP:
            changeState(StateID::RUN);
            break;
        case StateID::RUN:
            changeState(StateID::SHUTDOWN);
            break;
        case StateID::SHUTDOWN:
            changeState(StateID::INIT);
            break;
        case StateID::ERROR:
            // Handle error state
            break;
        default:
            break;
    }
}
