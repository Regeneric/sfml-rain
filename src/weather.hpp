#ifndef _WEATHER_HPP_
#define _WEATHER_HPP_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <vector>

#define Rectangle sf::RectangleShape
#define Circle sf::CircleShape

using std::make_unique; using std::vector;

class Cloud {
  public:
    Cloud(vector<Rectangle> &);
    ~Cloud();

  private:
    float _length, _width;
    float _posX, _posY;
};

class Drop {

  public:
    Drop();
    ~Drop();

    void fall();
    Rectangle show();

  private:
    float x, y;
    float ySpeed;
    float length;

};

#endif  //_WEATHER_HPP_
