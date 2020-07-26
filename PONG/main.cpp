#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;
    // Okno 1024 na 768 pikseli o nazwie "Pong"
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");
    window.sf::Window::setFramerateLimit(0);

    int P1score = 0;
    int P2score = 0;
    bool botmode = false;
    std::string trybBota = "OFF";
    



    // dwa baty i pi³ka
    Bat bat1(windowWidth - 1000, windowHeight / 2);
    Bat bat2(windowWidth - 24, windowHeight / 2);

    Ball ball(windowWidth / 2, windowHeight /2);

    // HUD u¿ywany do wyœwietlania wyniku
    sf::Text hud;

    // Ustawienia HUDa
    sf::Font font;
    font.loadFromFile("bit5x3.ttf");

    hud.setFont(font);

    hud.setCharacterSize(50);

    hud.setFillColor(sf::Color::White);

    // Pêtla gry
    while (window.isOpen())
    {
        /*
        Obs³uga przycisków
        */

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                // zamykanie okna
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    // escape zamyka
                    window.close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                {
                    if (botmode == true) {
                        botmode = false;
                    }
                    else {
                        botmode = true;
                    }
                    if (botmode == false) {
                        trybBota = "OFF";
                    }
                    else {
                        trybBota = "ON";
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                {
                    P1score = 0;
                    P2score = 0;
                    ball.reset();
                    bat1.reset();
                    bat2.reset();
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // P1 w dó³
            if (bat1.getPosition().top > windowHeight-70) {
                bat1.moveUp();
            }
            else {
                bat1.moveDown();
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // P1 w górê
            if (bat1.getPosition().top < 0) {
                bat1.moveDown();
            }
            else {
                bat1.moveUp();
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            if (botmode == false) {
                //P2 w dó³
                if (bat2.getPosition().top > windowHeight - 70) {
                    bat2.moveUp();
                }
                else {
                    bat2.moveDown();
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            if (botmode == false) {
                // P2 w górê
                if (bat2.getPosition().top < 0) {
                    bat2.moveDown();
                }
                else {
                    bat2.moveUp();
                }
            }
        }
        

        /*
        Aktualizacja ramki obrazu
        */

        //obs³uga AI
        if (botmode == true) {
            if (ball.getPosition().left > 512) {
                if (ball.getPosition().top - 35 > bat2.getPosition().top) {
                    bat2.moveDown();
                }
                else {
                    bat2.moveUp();
                }
            }
        }


        // Obs³uga odbica o górê lub dó³
        if (ball.getPosition().top < 0 || ball.getPosition().top > windowHeight)
        {
            ball.hitBottomOrTop();
        }

        // Obs³uga trafieñ i zdobywania punktów
        if (ball.getPosition().left < 0)
        {
            ball.hitSides(0);
            P2score++;
        }
        if (ball.getPosition().left + 10 > windowWidth)
        {
            ball.hitSides(1);
            P1score++;
        }

        // Obs³uga kolizji z batem
        if (ball.getPosition().intersects(bat1.getPosition()))
        {
            ball.reboundBat();
        }
        if (ball.getPosition().intersects(bat2.getPosition()))
        {
            ball.reboundBat();
        }

        ball.update();
        bat1.update();
        bat2.update();

        // Aktualizowanie wyniku
        std::stringstream ss;
        ss << "               P1:" << P1score << "    P2:" << P2score << "       AI:" << trybBota;
        hud.setString(ss.str());

        /*
        Rysowanie klatki obrazu
        */

        // Wyczyszczenie poprzedniej klatki

        window.clear(sf::Color(0, 0, 0, 255));

        window.draw(bat1.getShape());
        window.draw(bat2.getShape());

        window.draw(ball.getShape());

        // Wypisanie wyniku
        window.draw(hud);

        // Rysowanie pi³ki i batów
        window.display();
    }

    return 0;
}