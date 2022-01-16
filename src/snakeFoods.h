#ifndef SNAKEFOODS_H
#define SNAKEFOODS_H

#include <vector>
#include <string>
typedef std::vector<int> ints;
class SnakeFoods
{
public:
    // Constructor & destructor
    SnakeFoods(int posX, int posY, int scoreVal, std::string foodName)
        : x_(posX), y_(posY), val_(scoreVal), name_(foodName) {}

    // Overloaded constructor
    // foodColor is RGB color, size is always 3
    SnakeFoods(int posX, int posY, int scoreVal, std::string foodName, std::vector<int> foodColor)
        : x_(posX), y_(posY), val_(scoreVal), name_(foodName), color_(foodColor) {}

    // get and set methods
    void setX(int x) { x_ = x; }
    int getX() { return x_; }

    void setY(int y) { y_ = y; }
    int getY() { return y_; }

    void setVal(int v) { val_ = v; }
    int getVal() { return val_; }

    void setName(std::string n) { name_ = n; }
    std::string getName() { return name_; }

    void setColor(std::vector<int> c) { color_ = c; }
    std::vector<int> getColor() { return color_; }
private:
    int x_{0};
    int y_{0};
    int val_{0};
    std::string name_{"Default"};
    std::vector<int> color_ = {255, 255, 0}; // initial color as yellow
};

/*good foods*/
// dFood: default food will increase speed
class DefFood : public SnakeFoods
{
public:
    DefFood(int x, int y) : SnakeFoods(x, y, 1, "Default") {}
};

// SuperFood: super food will add a lot score (20), color white
class SuperFood : public SnakeFoods
{
public:
    SuperFood(int x, int y) : SnakeFoods(x, y, 20, "Superb", {230, 230, 250}) {}
};
#endif