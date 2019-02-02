#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

#include "weather.hpp"

#define Rectangle sf::RectangleShape
#define Circle sf::CircleShape

using std::make_unique; using std::vector;

auto main() -> int {

  sf::RenderWindow app;
    app.create(sf::VideoMode(640, 360, 32), "Rain");
    app.setFramerateLimit(60);

  // auto rain = make_unique<Drop>();
  vector<Drop> rain;
    rain.resize(200);

  while (app.isOpen()) {
    sf::Event event;
    while (app.pollEvent(event)) {
      if (event.type == sf::Event::Closed) app.close();
    } app.clear(sf::Color(230, 230, 250));

    for (int i = 0; i < rain.size(); i++) {
      rain[i].fall();
      app.draw(rain[i].show());
    }


    app.display();
  }

  return 0;
}
