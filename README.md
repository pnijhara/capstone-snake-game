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
| **Object Oriented Programming**<br />Uses Object Oriented Programming techniques. | Four classes are employed: [Snake](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/snake.h), [Controller](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/controller.h), [Game](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/game.h), and [Renderer](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/renderer.h), encapsulating data and control logic. |
| **Memory Management**<br />Makes use of references in function declarations. | Examples include [Renderer](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/renderer.h#L39) and [Game](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/game.h#L83) functions using pass-by-reference. |
| **Memory Management**<br />Uses smart pointers instead of raw pointers. | A vector of shared pointers is used to manage multiple snakes, as seen [here](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/game.h#L90). |
| **Memory Management**<br />Uses destructor(s) appropriately. | The [Renderer destructor](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/renderer.h#L28) is employed to close the window and perform cleanup after the game ends. |
