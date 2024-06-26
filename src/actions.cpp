#include "actions.h"
#include <iostream>

void initEntryAction() {
    std::cout << "Entering INIT state..." << std::endl;
}

void initRunningAction() {
    std::cout << "Running INIT state..." << std::endl;
}

void initExitAction() {
    std::cout << "Exiting INIT state..." << std::endl;
}

void powerUpEntryAction() {
    std::cout << "Entering POWERUP state..." << std::endl;
}

void powerUpRunningAction() {
    std::cout << "Running POWERUP state..." << std::endl;
}

void powerUpExitAction() {
    std::cout << "Exiting POWERUP state..." << std::endl;
}

void runEntryAction() {
    std::cout << "Entering RUN state..." << std::endl;
}

void runRunningAction() {
    std::cout << "Running RUN state..." << std::endl;
}

void runExitAction() {
    std::cout << "Exiting RUN state..." << std::endl;
}

void shutdownEntryAction() {
    std::cout << "Entering SHUTDOWN state..." << std::endl;
}

void shutdownRunningAction() {
    std::cout << "Running SHUTDOWN state..." << std::endl;
}

void shutdownExitAction() {
    std::cout << "Exiting SHUTDOWN state..." << std::endl;
}

void errorEntryAction() {
    std::cout << "Entering ERROR state..." << std::endl;
}

void errorRunningAction() {
    std::cout << "Running ERROR state..." << std::endl;
}

void errorExitAction() {
    std::cout << "Exiting ERROR state..." << std::endl;
}
