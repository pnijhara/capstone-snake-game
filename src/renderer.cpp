#include "renderer.h"
#include <iostream>
#include <string>

namespace SDL {

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width,
                   const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(
    const std::vector<std::shared_ptr<Capstone::Snake>> &snakes,
    const std::vector<SDL_Point> &foods,
    const std::vector<SDL_Point> &poisons) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  for (auto const &food : foods) {
    int snakeId = GetSnakeIdForFood(food, snakes);
    SDL_Color color = GetSnakeColor(snakeId);
    SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render poison
  for (auto const &poison : poisons) {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    block.x = poison.x * block.w;
    block.y = poison.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  for (auto const snake : snakes) {
    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : snake->body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(snake->head_x) * block.w;
    block.y = static_cast<int>(snake->head_y) * block.h;
    SDL_Color headColor = GetSnakeColor(snake->GetSnakeId());
    SDL_SetRenderDrawColor(sdl_renderer, headColor.r, headColor.g, headColor.b, headColor.a);
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score_left, int score_right, int fps) {
  std::string title{"Left Snake Score: " + std::to_string(score_left) + " " + \
  "Right Snake Score: " + std::to_string(score_right) + " FPS: " +
                    std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

int Renderer::GetSnakeIdForFood(SDL_Point food, const std::vector<std::shared_ptr<Capstone::Snake>> &snakes) {
  for (const auto &snake : snakes) {
    if (snake->SnakeCell(food.x, food.y)) {
      return snake->GetSnakeId();
    }
  }
  return -1;  // Return -1 if no snake found at the food location
}

SDL_Color Renderer::GetSnakeColor(int snakeId) {
  // Assuming two snakes, blue for snake 0, and green for snake 1
  SDL_Color color;
  if (snakeId == 0) {
    color = {0x00, 0x00, 0xFF, 0xFF};  // Blue
  } else if (snakeId == 1) {
    color = {0x00, 0xFF, 0x00, 0xFF};  // Green
  } else {
    color = {0xFF, 0xFF, 0xFF, 0xFF};  // White (default color)
  }
  return color;
}

}  // namespace SDL
