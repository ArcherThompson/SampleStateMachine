#include "state.h"
#include <iostream>

State::State(StateID id, Action onEntry, Action onRunning, Action onExit, int duration)
    : id(id), onEntry(onEntry), onRunning(onRunning), onExit(onExit), duration(duration), timerExpired(false) {}

void State::entry() {
    if (onEntry) onEntry();
    startTime = std::chrono::steady_clock::now();
    timerExpired = false;
}

void State::running() {
    if (onRunning) onRunning();
    checkTimer();
}

void State::exit() {
    if (onExit) onExit();
}

bool State::isTimerExpired() const {
    return timerExpired;
}

StateID State::getID() const {
    return id;
}

void State::checkTimer() {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    if (elapsed >= duration) {
        timerExpired = true;
    }
}
