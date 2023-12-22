// Main.cpp to compile all files and run the game
#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  // Constants for game settings
  constexpr std::size_t FramesPerSecond{60};
  constexpr std::size_t MsPerFrame{1000 / FramesPerSecond};
  constexpr std::size_t ScreenWidth{1280};
  constexpr std::size_t ScreenHeight{1280};
  constexpr std::size_t GridWidth{32};
  constexpr std::size_t GridHeight{32};

  do {
    // Create SDL Renderer and Controller instances
    SDL::Renderer gameRenderer(ScreenWidth, ScreenHeight, GridWidth, GridHeight);
    SDL::Controller gameController;

    // Create the game instance with specified grid dimensions
    Game snakeGame(GridWidth, GridHeight);

    // Run the game loop
    snakeGame.Run(gameController, gameRenderer, MsPerFrame);

    // Determine and display game outcome
    if (!snakeGame.GetBlueStatus() && snakeGame.GetGreenStatus()) {
      std::cout << "Blue Snake ate poison, Green Snake Wins!" << "\n";
    } else if (snakeGame.GetBlueStatus() && !snakeGame.GetGreenStatus()) {
      std::cout << "Green Snake ate poison, Blue Snake Wins!" << "\n";
    } else {
      std::cout << "Game has terminated successfully!\n";
      std::cout << "ScoreBlue: " << snakeGame.GetBlueScore() << "\n";
      std::cout << "SizeBlue: " << snakeGame.GetBlueSize() << "\n";
      std::cout << "ScoreGreen: " << snakeGame.GetGreenScore() << "\n";
      std::cout << "SizeGreen: " << snakeGame.GetGreenSize() << "\n";

      // Determine the winner or declare a tie
      if (snakeGame.GetBlueScore() > snakeGame.GetGreenScore()) {
        std::cout << "Blue Snake Wins!" << "\n";
      } else if (snakeGame.GetBlueScore() < snakeGame.GetGreenScore()) {
        std::cout << "Green Snake Wins!" << "\n";
      } else {
        std::cout << "It's a Tie!" << "\n";
      }
    }

    std::string playAgain;
    std::cout << "Do you want to play again? (yes/no): ";
    std::cin >> playAgain;

    if (playAgain != "yes") {
      break;
    }

  } while (true);

  return 0;
}
