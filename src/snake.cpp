#include "snake.h"
#include <cmath>
#include <iostream>

Snake::Snake() {}

Snake::Snake(const int& grid_width, const int& grid_height, int&& num)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width),
        head_y(grid_height * 0.75f)
        {
          if (num == 0)
            head_x = grid_width * 0.25;
          else
            head_x = grid_width * 0.75;           
        }

Snake::~Snake() {}

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

bool Snake::SnakeCell(const int &x, const int &y)
{
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y))
  {
    return true;
  }
  for (auto const &item : body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}

/* below are all newly added functions */

void Snake::askGrowingSpeed(){
  float mySpeed = 0.0;
  std::cout << "How fast would you like your snake to grow?" << std::endl;
  std::cout << "Please enter a decimal number between 0 (slowest) to 1 (faestest): " << std::endl;
  std::cin >> mySpeed;
  std::cout << "You have entered speed = " << mySpeed << ". Enjoy!"  << std::endl;
  Snake::growSpeed = mySpeed;
  return;
}

bool Snake::EatFood(SDL_Point& food){
  bool ateFood = false;
  int new_x = static_cast<int>(head_x);
  int new_y = static_cast<int>(head_y);

  if (food.x == new_x && food.y == new_y)
  {
    score++;
    GrowBody();
    ateFood = true;
  }
  return ateFood;

}
