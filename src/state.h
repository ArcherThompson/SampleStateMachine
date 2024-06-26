#ifndef STATE_H
#define STATE_H

#include <functional>
#include <chrono>
#include <string>

enum class StateID {
    INIT,
    POWERUP,
    RUN,
    SHUTDOWN,
    ERROR
};

class State {
public:
    using Action = std::function<void()>;

    State() : id(StateID::INIT), duration(0), timerExpired(false) {}  // Default constructor
    State(StateID id, Action onEntry, Action onRunning, Action onExit, int duration);

    void entry();
    void running();
    void exit();

    bool isTimerExpired() const;
    StateID getID() const;

private:
    StateID id;
    Action onEntry;
    Action onRunning;
    Action onExit;
    int duration; // in seconds
    bool timerExpired;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

    void checkTimer();
};

#endif // STATE_H
