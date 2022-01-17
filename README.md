## Chosen Project Name
2D Snake games

## Code Criterion

Please check on PlotExplain.png for what have been added and how they flow

1. Loops, Function and I&O

#1.1
  The project demonstrates an understanding of C++ functions and control structures
  --> DONE:
  ---> Snake::askGrowingSpeed() this function, which called in game::run
  ---> SnakeFoods also met this spec

#1.3
  The project accepts user input and processes the input.
  --> DONE:
  ---> Snake::askGrowingSpeed ask user enter their snake growing speed, and this speed to growing snake during the game

2. OOP

#2.1
  The project uses Object Oriented Programming techniques.
  --> DONE:
  ---> SnakeFoods class is designed as OOP
  ---> refatored Snake, Game these two classes for OOP

#2.2 
  Classes use appropriate access specifiers for class members
  --> DONE:
  ---> Set&get methods inside SnakeFoods to access its members
  ---> Snake class members been assigned to propriate type:
       moved below two functions into public
       void Update();
       void GrowBody();
       bool SnakeCell(const int &x, const int &y);


#2.3 
  Class constructors utilize member initialization lists.
  --> Done:
  ---> SnakeFoods
  ---> Snake::Snake(int grid_width, int grid_height);

#2.4 
  Classes abstract implementation details from their interfaces.
  --> Done
  ---> See SnakeFoods class

#2.5 
  Classes follow an appropriate inheritance hierarchy
  --> Done
  ---> See SnakeFoods class and its children DefFood and SuperFood


#2.6 
  Overloaded functions allow the same function to operate on different parameters.
  --> Done
  ---> See SnakeFoods class

3. Memory Management

#3.1 
  The project makes use of references in function declarations.
  At least two variables are defined as references, or two functions use pass-by-reference in the project code.
  --> Done:
  ---> bool Snake::SnakeCell(const int &x, const int &y) two inputs as reference 

#3.2
  The project uses destructors appropriately.
  --> Done
  ---> snake.h ~Snake()

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
5. Enter snake growing speed in terminal console
6. Play && Enjoy!
