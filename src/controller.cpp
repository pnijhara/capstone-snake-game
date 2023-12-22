#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void SDL::Controller::ChangeDirection(std::shared_ptr<Capstone::Snake> snake,
                                      Capstone::Snake::Direction input,
                                      Capstone::Snake::Direction opposite) const {
  if (snake->direction != opposite || snake->size == 1)
    snake->direction = input;
}

void SDL::Controller::HandleInput(bool &running,
                                  std::vector<std::shared_ptr<Capstone::Snake>> &snakes) const {
  SDL_Event e;
  auto snakeBlue = snakes[0];
  auto snakeGreen = snakes[1];
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      using namespace Capstone;
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snakeGreen, Snake::Direction::kUp, Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snakeGreen, Snake::Direction::kDown, Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snakeGreen, Snake::Direction::kLeft, Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snakeGreen, Snake::Direction::kRight, Snake::Direction::kLeft);
          break;

        case SDLK_w:
          ChangeDirection(snakeBlue, Snake::Direction::kUp, Snake::Direction::kDown);
          break;

        case SDLK_s:
          ChangeDirection(snakeBlue, Snake::Direction::kDown, Snake::Direction::kUp);
          break;

        case SDLK_a:
          ChangeDirection(snakeBlue, Snake::Direction::kLeft, Snake::Direction::kRight);
          break;

        case SDLK_d:
          ChangeDirection(snakeBlue, Snake::Direction::kRight, Snake::Direction::kLeft);
          break;
      }
    }
  }
}
