#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Texto
{
private:
    Font font;
    Text red;
    Text cyan;

public:
    Texto(/* args */) {}
    ~Texto() {}
    void loadFont()
    {
        if (!font.loadFromFile("./assets/fonts/CENTAUR.TTF"))
        {
            throw("Error: No se pudo cargar la fuente");
        }

    }
    void loadCyan()
    {
        cyan.setFont(font);
        cyan.setCharacterSize(24);
        cyan.setFillColor(Color::Cyan);
        cyan.setString("Cyan: ");
        cyan.setPosition(0, 0);
    }
    void loadRed()
    {
        red.setFont(font);
        red.setCharacterSize(24);
        red.setFillColor(Color::Red);
        red.setString("Red: ");
        red.setPosition(650, 0);
    }
    void setStringCyan(int player1Score)
    {
        std::stringstream ss;
        ss << (player1Score);
        std::string si;
        ss >> si;
        red.setString("Red: " + si);
    }
    void setStringRed(int player2Score)
    {
        std::stringstream ss2;
        ss2 << (player2Score);
        std::string si2;
        ss2 >> si2;
        cyan.setString("Cyan: " + si2);
    }
    Text getCyan()
    {
        return cyan;
    }
    Text getRed()
    {
        return red;
    }
};

#endif