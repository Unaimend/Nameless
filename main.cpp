#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Logfile.h"
#include "Framework.hpp"

int main(int, char const**)
{
    Framework framework;
    framework.Run();
    
    
    return 0;
}


//  std::string test("abcdefghijklmnopfqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
/*
sf::Uint8 unicode;
while (window->pollEvent(event))
{////////////////////////////////////////////////////////////
    if (event.type == sf::Event::TextEntered) {//
        unicode = event.text.unicode;           //
        unicode = static_cast<char>(unicode);
        if (test.find(unicode) < 100    )
        {
            std::cout << unicode << std::endl;
        }
}*/


//TODO(Thomas) Change the Maprenderer Iterator so that it reads two values e.g. "83" instead of "8" and then "3";