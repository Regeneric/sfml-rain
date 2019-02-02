#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "weather.hpp"

#define Rectangle sf::RectangleShape
#define Circle sf::CircleShape

using std::make_unique; using std::vector;

Cloud::Cloud(vector<Rectangle> &raindrop) {

  int it = 10;

  //setting up raindrop
  srand(rand());
  _length = 2;

  for (int i = 0; i < raindrop.size(); i++) {
    _width = rand()%15+3;
    _posX = rand()%800;
    _posY += it;

    raindrop[i].setFillColor(sf::Color::Blue);
    raindrop[i].setSize(sf::Vector2f(_length, _width));
    raindrop[i].setPosition(_posX, _posY);
  }

}

Cloud::~Cloud() {}

Drop::Drop() {
  srand(rand());

  x = rand()%640;
  y = (rand()%200-100);
  ySpeed = rand()%14+6;
  length = rand()%20+10;

}

Drop::~Drop() {}

void Drop::fall() {
  y += ySpeed;
  ySpeed += 0.2;

  if (y > 360) {
    y = 0;
    ySpeed = rand()%14+6;
  }
}

Rectangle Drop::show() {
  Rectangle drop;
    drop.setPosition(x, y);
    drop.setSize(sf::Vector2f(2, length));
    drop.setFillColor(sf::Color(138, 43, 226));
  return drop;
}
