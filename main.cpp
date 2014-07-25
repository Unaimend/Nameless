#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


#include "Framework.hpp"
int main(int, char const**)
{

    Framework framework;
    std::cout << "Framework läuft   " << std::endl;

    framework.Run();
    
    return 0;
}
