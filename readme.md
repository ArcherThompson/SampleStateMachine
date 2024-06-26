# State Machine Project

This project demonstrates a simple state machine implementation in C++ with multiple states including INIT, POWERUP, RUN, SHUTDOWN, and ERROR.


## Building the Project

### Prerequisites

- `g++` (GNU C++ Compiler)
- `make` (Build automation tool)

### Steps to Build

1. **Navigate to the project directory**:
    ```sh
    cd /path/to/project
    ```

2. **Clean the build environment** (optional but recommended to remove any previous builds):
    ```sh
    make clean
    ```

3. **Build the project**:
    ```sh
    make
    ```

   This will compile the source files from the `src` directory and place the object files and the final executable in the `build` directory.

4. **Run the executable**:
    ```sh
    ./build/state_machine
    ```

## Project Files

- **src/main.cpp**: Contains the `main` function which drives the state machine.
- **src/state.h / src/state.cpp**: Declaration and definition of the `State` class.
- **src/statemachine.h / src/statemachine.cpp**: Declaration and definition of the `StateMachine` class.
- **src/actions.h / src/actions.cpp**: Declarations and definitions of the state action functions.

## Clean Up

To remove the built files and the executable, run:
```sh
make clean
