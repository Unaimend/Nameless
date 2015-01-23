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
        unicode = static_cast<  char>(unicode);
        if (test.find(unicode) < 100 )
        {
            std::cout << unicode << std::endl;
        }
}*/


//Das komplette Tilesystem neuschreiben so, dass jedes Tile einer Klasse entspricht von der ich die Position und Art abfragen kann, damit ich spezielle bereiche wie Spawnareas, Zäune etc erstellen kann, denn dadurch kann man easy colision etc. machen.