#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Movement
{
private:
    /* data */
public:
    Movement(/* args */) {}
    ~Movement() {}
    void movePlayer1(int &dx, int &dy, int size)
    {
        if (Keyboard::isKeyPressed(Keyboard::Left) && dx != size)
        {
            dx = -size;
            dy = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && dx != -size)
        {
            dx = size;
            dy = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && dy != size)
        {
            dy = -size;
            dx = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && dy != -size)
        {
            dy = size;
            dx = 0;
        }
    }

    void movePlayer2(int &dx2, int &dy2, int size)
    {
       if (Keyboard::isKeyPressed(Keyboard::A) && dx2 != size)
        {
            dx2 = -size;
            dy2 = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && dx2 != -size)
        {
            dx2 = size;
            dy2 = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::W) && dy2 != size)
        {
            dy2 = -size;
            dx2 = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && dy2 != -size)
        {
            dy2 = size;
            dx2 = 0;
        }
    }
};

#endif // MOVEMENT_HPP