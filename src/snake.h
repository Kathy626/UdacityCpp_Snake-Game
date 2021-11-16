#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
 // constructor & desctructor
  Snake();
  Snake(int grid_width, int grid_height);
  ~Snake();

  enum class Direction { kUp, kDown, kLeft, kRight };
  Direction direction = Direction::kUp;

  // member
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  /* OOP 1.2: Update() and GrowBody() called in game.cpp, so move to public*/
  void Update();
  void GrowBody();
  bool SnakeCell(const int &x, const int &y);

  // new: get growing speed
  float growSpeed{0.02f};
  void askGrowingSpeed();

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif