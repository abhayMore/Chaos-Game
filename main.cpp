#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

class Quadrilateral
{
private:
    sf::CircleShape quad;
    sf::CircleShape circle;

    int count;
    float Variable;

    sf::Vector2f CircleXY;

public:
    Quadrilateral(int VertexNumber, float DistanceFactor);

    void Movement();
    sf::CircleShape &DrawCircle();
    sf::CircleShape &DrawQuad();
    void CircleSetPosition(sf::Vector2f, sf::Vector2f);
};
Quadrilateral::Quadrilateral(int VertexNumber, float DistanceFactor) : CircleXY(300.0f, 500.0f), count(VertexNumber), Variable(DistanceFactor)
{
    srand(time(0));
    quad.setRadius(300);
    quad.setPointCount(count);

    quad.setOutlineThickness(0.8);
    quad.setFillColor(sf::Color::Transparent);

    circle.setRadius(1);
    circle.setPosition(CircleXY);
    circle.setFillColor(sf::Color::Magenta);
}

void Quadrilateral::CircleSetPosition(sf::Vector2f TRI, sf::Vector2f CIR)
{
    float PositionX = (TRI.x * (1 - Variable) + CIR.x * Variable);
    float PositionY = (TRI.y * (1 - Variable) + CIR.y * Variable);

    circle.setPosition(PositionX, PositionY);
}

void Quadrilateral::Movement()
{
    int random = rand() % (count * 2 ) + 1;

    if (count == 4)
    {
        if(random < 5)
        {
            CircleSetPosition(quad.getPoint((random - 1)), CircleXY);
        }
        else if (random == 5)
        {
            sf::Vector2f temp((quad.getPoint(0).x + quad.getPoint(1).x) / 2, (quad.getPoint(0).y + quad.getPoint(1).y) / 2);
            CircleSetPosition(temp, CircleXY);
        }
        else if (random == 6)
        {
            sf::Vector2f temp((quad.getPoint(1).x + quad.getPoint(2).x) / 2, (quad.getPoint(1).y + quad.getPoint(2).y) / 2);
            CircleSetPosition(temp, CircleXY);
        }
        else if (random == 7)
        {
            sf::Vector2f temp((quad.getPoint(0).x + quad.getPoint(3).x) / 2, (quad.getPoint(0).y + quad.getPoint(3).y) / 2);
            CircleSetPosition(temp, CircleXY);
        }
        else if (random == 8)
        {
            sf::Vector2f temp((quad.getPoint(2).x + quad.getPoint(3).x) / 2, (quad.getPoint(2).y + quad.getPoint(3).y) / 2);
            CircleSetPosition(temp, CircleXY);
        }
    }
    else
    {
        if (random % 2 == 0)
            CircleSetPosition(quad.getPoint((random - 2) / 2), CircleXY);
        else
            CircleSetPosition(quad.getPoint((random - 1) / 2), CircleXY);
    }
    CircleXY = circle.getPosition();
}

sf::CircleShape &Quadrilateral::DrawCircle()
{
    return circle;
}

sf::CircleShape &Quadrilateral::DrawQuad()
{
    return quad;
}

int main()
{
    std::cout << "Enter Vertex Number and Distance factor" << std::endl;
    int VertexNumber;
    float DistanceFactor;
    std::cin >> VertexNumber >> DistanceFactor;

    Quadrilateral Shape(VertexNumber, DistanceFactor);

    sf::RenderWindow window(sf::VideoMode(800, 600), "ChaosGame");

    // comment below line if want to increase the FPS and uncomment below "window.setFramerateLimit(120);" and give necessary FPS.
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(120);

    sf::RenderTexture canvas;
    canvas.create(800,600);
    sf::Sprite sprite;
    sprite.setTexture(canvas.getTexture(), true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Shape.Movement();

        canvas.draw(Shape.DrawCircle());
        canvas.display();

        window.clear();

        window.draw(sprite);
	      window.draw(Shape.DrawQuad());

        window.display();
    }
}
