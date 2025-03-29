#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* window;
    sf::Clock frameClock;
    float sunRadius;
    bool increasing;

public:
    Cvijet(sf::RenderWindow* window) : window(window), sunRadius(35.0f), increasing(false) {}

    void draw() {
        // Update sun size
        sf::Time elapsed = frameClock.getElapsedTime();
        if (elapsed.asSeconds() > 0.1f) {
            if (increasing) {
                sunRadius += 1.0f;
                if (sunRadius >= 35.0f) {
                    increasing = false;
                }
            }
            else {
                sunRadius -= 1.0f;
                if (sunRadius <= 5.0f) {
                    increasing = true;
                }
            }
            frameClock.restart();
        }

        // Draw sun
        sf::CircleShape sun(sunRadius);
        sun.setFillColor(sf::Color(255, 255, 0));
        sun.setPosition(700, 50);
        window->draw(sun);

        // Draw stem
        sf::RectangleShape stem(sf::Vector2f(10, 200));
        stem.setFillColor(sf::Color(0, 128, 0));
        stem.setPosition(395, 400);
        window->draw(stem);

        // Draw leaf
        sf::ConvexShape leaf;
        leaf.setPointCount(3);
        leaf.setPoint(0, sf::Vector2f(395, 500)); 
        leaf.setPoint(1, sf::Vector2f(395, 450)); 
        leaf.setPoint(2, sf::Vector2f(445, 475)); 
        leaf.setFillColor(sf::Color(0, 128, 0));
        window->draw(leaf);

        // Draw petals
        sf::CircleShape petal(50);
        petal.setFillColor(sf::Color(127, 0, 255));
        petal.setPosition(350, 300);
        window->draw(petal);

        petal.setPosition(450, 300);
        window->draw(petal);

        petal.setPosition(450, 300);
        window->draw(petal);

        petal.setPosition(400, 250);
        window->draw(petal);

        petal.setPosition(400, 350);
        window->draw(petal);

        // Draw center
        sf::CircleShape center(50);
        center.setFillColor(sf::Color(255, 255, 0));
        center.setPosition(400, 300);
        window->draw(center);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
    window.setFramerateLimit(60);
    Cvijet cvijet(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        cvijet.draw();
        window.display();
    }

    return 0;
}