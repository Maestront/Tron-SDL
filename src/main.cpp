#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include "Movement.hpp"
#include "Texto.hpp"

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

Movement m;

int main()
{
    RenderWindow window(VideoMode(W * size, H * size), "Tron");
    Texture t1, t2, t3;
    t1.loadFromFile("./assets/images/background.png");
    t2.loadFromFile("./assets/images/player1.png");
    t3.loadFromFile("./assets/images/player2.png");

    Sprite Background(t1), Player1(t2), Player2(t3);

    float timer = 0, delay = 0.05;
    Clock clock;

    Texto tx;

    tx.loadFont();
    tx.loadCyan();
    tx.loadRed();

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
        
        m.movePlayer1(dx, dy, size);
        
        // Moving Player2 - W A S D     

        m.movePlayer2(dx2, dy2, size);

        if (timer > delay) // time
        {
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
            if (gameArray[y / size][x / size] == 1 && gameArray[y2 / size][x2 / size] != 2)
            {
                player1Counter++;
                player2Score++;
            }

            // Collision Player2
            if (gameArray[y2 / size][x2 / size] == 2 && gameArray[y / size][x / size] != 1)
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

        // Retyping int to string red
        tx.setStringCyan(player1Score);

        // Retyping int to string cyan
        tx.setStringRed(player2Score);

        window.draw(tx.getCyan());
        window.draw(tx.getRed());

        if (player1Counter > 0 || player2Counter > 0) // GameLoop
        {
            sf::sleep(sf::microseconds(250));
            x = 39 * size;
            y = 15 * size;
            x2 = 5 * size;
            y2 = 15 * size;
            player1Counter = 0;
            player2Counter = 0;
            for (int i = 0; i < H; i++) // set each element in the array to zero
            {
                for (int j = 0; j < W; j++)
                {
                    gameArray[i][j] = 0;
                }
            }
        }

        window.display();
    }

    return 0;
}