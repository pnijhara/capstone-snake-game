#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
public:
  // Constructor initializes the game with snakes, food, and poison
  Game(std::size_t grid_width, std::size_t grid_height);

  // Function to start the game loop
  void Run(SDL::Controller const &controller, SDL::Renderer &renderer, std::size_t target_frame_duration);

  // Getter functions for blue snake's score, size, green snake's score, size, and their status
  int GetBlueScore() const;
  int GetBlueSize() const;
  int GetGreenScore() const;
  int GetGreenSize() const;
  bool GetBlueStatus() const;
  bool GetGreenStatus() const;

private:
  // Function to place food on the board at locations where snake's body is absent
  void PlaceFood(SDL_Point &food);

  // Function to place poison on the board where snake's body is not present
  void PlacePoison(SDL_Point &poison);

  // Update the game state
  void Update();

  // Collection of snakes in the game
  std::vector<std::shared_ptr<Capstone::Snake>> snakes_;

  // Collection of food items on the board
  std::vector<SDL_Point> foods;
  const int food_size = 5;

  // Collection of poison items on the board
  std::vector<SDL_Point> poisons;
  const int poison_size = 3;

  // Random number generator for placing food and poison
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  // Scores for blue and green snakes
  int score_blue{0};
  int score_green{0};

  // Flags indicating whether blue and green snakes are alive
  bool blue_alive = true;
  bool green_alive = true;
};

#endif
