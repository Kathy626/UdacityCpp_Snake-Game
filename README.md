## Chosen Project Name
2D Snake games

## Code Criterion
1. Loops, Function and I&O
#1.1 (Task 1)
  Spec: The project demonstrates an understanding of C++ functions and control structures
  ---> Snake::askGrowingSpeed() this function

#1.3 (Task 2)
  The project accepts user input and processes the input.
  ---> Snake::askGrowingSpeed ask user decide their snake growing speed

2. OOP
#2.1 (Task 3)
  The project uses Object Oriented Programming techniques.
  ---> refatored Snake, Game these two classes for OOP

#2.2 (Task 4)
  Classes use appropriate access specifiers for class members
  ---> Snake class members been assigned to propriate type:
       moved below two functions into public
       void Update();
       void GrowBody();

#2.3 (Task 5)
  Class constructors utilize member initialization lists.
  ---> Snake::Snake(int grid_width, int grid_height);

  
3. Memory Management
#3.1 (Task 6)
  The project makes use of references in function declarations.
  At least two variables are defined as references, or two functions use pass-by-reference in the project code.
  ---> bool Snake::SnakeCell(const int &x, const int &y) two inputs as reference 

#3.2 (Task 7)
  The project uses destructors appropriately.
  --> snake.h ~Snake()

4. Concurrency
NO

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

