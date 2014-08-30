#include "Item.h"


void Item::render(sf::RenderWindow *window)
{
    window->draw(mSprite);
   // std::cout << "FALSCHE RENDERFUNKTION";
};

void Item::update(double frametime)
{
std::cout << "FALSCHE UPDATE";
};