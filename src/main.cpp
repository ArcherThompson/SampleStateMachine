#include "state.h"
#include "statemachine.h"
#include "actions.h"
#include <thread>
#include <chrono>

int main() {
    StateMachine stateMachine(StateID::INIT);

    stateMachine.addState(StateID::INIT, State(StateID::INIT, initEntryAction, initRunningAction, initExitAction, 2));
    stateMachine.addState(StateID::POWERUP, State(StateID::POWERUP, powerUpEntryAction, powerUpRunningAction, powerUpExitAction, 3));
    stateMachine.addState(StateID::RUN, State(StateID::RUN, runEntryAction, runRunningAction, runExitAction, 5));
    stateMachine.addState(StateID::SHUTDOWN, State(StateID::SHUTDOWN, shutdownEntryAction, shutdownRunningAction, shutdownExitAction, 4));
    stateMachine.addState(StateID::ERROR, State(StateID::ERROR, errorEntryAction, errorRunningAction, errorExitAction, 1));

    // Simulate state machine operation
    for (int i = 0; i < 20; ++i) {
        stateMachine.runCurrentState();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
