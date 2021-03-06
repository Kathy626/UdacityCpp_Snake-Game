#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game() {}
Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
  PlaceFood();
}
Game::~Game() {}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  snake.askGrowingSpeed(); // Newly Added

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food); 

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }
  }

  // If the time for this frame is too small (i.e. frame_duration is
  // smaller than the target ms_per_frame), delay the loop to
  // achieve the correct frame rate.
  if (frame_duration < target_frame_duration)
  {
    SDL_Delay(target_frame_duration - frame_duration);
  }
}


void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);

    if (!snake.SnakeCell(x, y)) 
    {
      break;
    }
  }
    /* NEW */
    /* Refered to Stackoverflow for random number within user defined range
     more detail see https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range */
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0,1); // guaranteed unbiased

    auto random_FruitIndex = uni(rng);
    switch((int)random_FruitIndex){
      case 0:
        food = DefFood(x,y);
        break;
      case 1:
        food = SuperFood(x,y);
        break;
    }
    // for testing
    std::cout << "Food = " << food.getName() << std::endl;
}

void Game::Update()
{
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.getX() == new_x && food.getY() == new_y)
  {
    score += food.getVal(); // change score based on food value
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += snake.growSpeed; // update per user input
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }