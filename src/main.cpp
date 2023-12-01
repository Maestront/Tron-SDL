#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>

using namespace sf;

const int W = 45; // Width - Ancho
const int H = 35; // Height - Alto

int size = 16; // 1 Square

// Player1
int x = 39 * size, y = 15 * size;
int dx = 0, dy = 0;
int player1Counter = 0;
int player1Score = 0;

int gameArray[H][W] = {0}; // GameArray

// Player2
int x2 = 5 * size, y2 = 15 * size;
int dx2 = 0, dy2 = 0;
int player2Counter = 0;
int player2Score = 0;

int main()
{
    RenderWindow window(VideoMode(W * size, H * size), "Tron");

    Texture t1, t2, t3;
    t1.loadFromFile("./assets/images/background.png");
    t2.loadFromFile("./assets/images/player1.png");
    t3.loadFromFile("./assets/images/player2.png");

    Sprite Background(t1), Player1(t2), Player2(t3);

    float timer = 0, delay = 0.1;
    Clock clock;

    Font font;
    if(!font.loadFromFile("./assets/fonts/CENTAUR.TTF"))
    {
        throw("Nope");
    }

    Text cyan, red;
    cyan.setFont(font);
    cyan.setCharacterSize(24);
    cyan.setFillColor(Color::Cyan);
    cyan.setString("Cyan: ");
    cyan.setPosition(0, 0);

    red.setFont(font);
    red.setCharacterSize(24);
    red.setFillColor(Color::Red);
    red.setString("Red: ");
    red.setPosition(665, 0);

    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        // Moving Player1 - LEFT RIGHT UP DOWN
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

        // Moving Player2 - W A S D
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

        if (timer > delay) // time
        {
            x += dx;
            y += dy;

            x2 += dx2;
            y2 += dy2;

            // Walking in Border Player1
            if (x >= (W * size))
                x = 0;
            if (x < 0)
                x = (W - 1) * size;

            if (y >= (H * size))
                y = 0;
            if (y < 0)
                y = (H - 1) * size;

            // Walking in Border Player2
            if (x2 >= (W * size))
                x2 = 0;
            if (x2 < 0)
                x2 = (W - 1) * size;

            if (y2 >= (H * size))
                y2 = 0;
            if (y2 < 0)
                y2 = (H - 1) * size;

            // Collision Player1
            if (gameArray[y / size][x / size] == 1 && (dx + dy) != 0 ||
                gameArray[y / size][x / size] == 2)
            {
                player1Counter++;
                player2Score++;
            }

            // Collision Player2
            if (gameArray[y2 / size][x2 / size] == 2 && (dx2 + dy2) != 0 ||
                gameArray[y2 / size][x2 / size] == 1)
            {
                player2Counter++;
                player1Score++;
            }

            if (gameArray[y / size][x / size] == 0)
                gameArray[y / size][x / size] = 1; // Write 1 in Array
            if (gameArray[y2 / size][x2 / size] == 0)
                gameArray[y2 / size][x2 / size] = 2; // Write 2 in Array

            timer = 0;
        }

        // Window//
        window.clear();

        for (int i = 0; i < H; i++) // Draw Background
        {
            for (int j = 0; j < W; j++)
            {
                if (gameArray[i][j] == 0)
                {
                    Background.setPosition(j * size, i * size);
                    window.draw(Background);
                }
                else if (gameArray[i][j] == 1)
                {
                    Player1.setPosition(j * size, i * size);
                    window.draw(Player1);
                }
                else if (gameArray[i][j] == 2)
                {
                    Player2.setPosition(j * size, i * size);
                    window.draw(Player2);
                }
            }
        }

        Player1.setPosition(x, y);
        window.draw(Player1);
        Player2.setPosition(x2, y2);
        window.draw(Player2);

        //Retyping int to string red
        std::stringstream ss;
        ss << (player1Score);
        std::string si;
        ss >> si;
        red.setString("Red: " + si);

        //Retyping int to string cyan
        std::stringstream ss2;
        ss2 << (player2Score);
        std::string si2;
        ss2 >> si2;
        cyan.setString("Cyan: " + si2);

        window.draw(cyan);  window.draw(red);

        if(player1Counter > 0 || player2Counter > 0) //GameLoop
        {
            sf::sleep(sf::microseconds(250));
            x = 39 * size; y = 15 * size;
            x2 = 5 * size; y2 = 15 * size;
            dx = 0; dy = 0;
            dx2 = 0; dy2 = 0;
            player1Counter = 0; player2Counter = 0;
            for(int i = 0; i < H; i++) //set each element in the array to zero
            {
                for(int j = 0; j < W; j++)
                {
                    gameArray[i][j] = 0;
                }
            }
        }

        window.display();
    }

    return 0;
}