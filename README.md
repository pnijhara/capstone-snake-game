# Multi-Player Snake Game

The Multi-Player Snake Game is an enhanced version of the original Snake Game provided as a part of Udacity's C++ Nanodegree Capstone Project. In this modification, a second snake is introduced for a multi-player experience, and a new element, poison, is added to make the game more challenging.

## Project Structure

```bash
capstone-snake
├── src  # Contains main source files
│   ├── main.cpp
│   ├── snake.h
│   ├── snake.cpp
│   ├── controller.h
│   ├── controller.cpp
│   ├── game.h
│   ├── game.cpp
│   ├── renderer.h
│   └── renderer.cpp
├── CMakeLists.txt
├── cmake
│   └── FindSDL2_image.cmake
├── README.md
```

## Dependencies for Running Locally

* cmake >= 3.7
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
* SDL2 >= 2.0
* gcc/g++ >= 5.4

## Basic Build Instructions

1. Clone this repository.
2. Create a build directory in the top-level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run the executable: `./SnakeGame`.

## Key Project Rubrics Addressed

| Category/Rubric                                              | Explanation and link(s)                                      |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Loops, Functions, I/O**<br />Demonstrates understanding of C++ functions and control structures. | The project maintains proper organization with the use of functions and structured data flow. |
| **Object Oriented Programming**<br />Uses Object Oriented Programming techniques. | Four classes are employed: Snake, Controller, Game, and Renderer, encapsulating data and control logic. |
| **Memory Management**<br />Makes use of references in function declarations. | Examples include Renderer and Game functions using pass-by-reference. |
| **Memory Management**<br />Uses smart pointers instead of raw pointers. | A vector of shared pointers is used to manage multiple snakes|
| **Memory Management**<br />Uses destructor(s) appropriately. | The Renderer destructor is employed to close the window and perform cleanup after the game ends. |
| **Concurrent Programming**<br />The project efficiently manages multiple players simultaneously within the main game loop. | The game loop handles input, update, and rendering processes concurrently for each player, providing a seamless multiplayer experience. The interleaved processing of player actions simulates a concurrent environment, allowing for real-time interactions between players. |
| **Concurrent Programming**<br />The project demonstrates effective synchronization mechanisms for multiplayer interactions. | To ensure a consistent gaming experience, the project implements synchronization mechanisms that prevent conflicts between players' actions. This includes proper handling of simultaneous inputs, updates, and rendering to maintain game integrity and avoid race conditions. |
