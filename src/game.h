#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "snakeFoods.h"// newly added to define different type of foods

class Game {
 public:
 // Constructor & desctructor
  Game();
  Game(std::size_t grid_width, std::size_t grid_height);
  ~Game();

  // public methods
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
 private:
  int score{0};

  Snake snake;
  
  //SDL_Point food;
  SnakeFoods food = DefFood(0,0);
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  void PlaceFood();
  void Update();
};

#endif