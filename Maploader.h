
#ifndef __Nameless__Maploader__
#define __Nameless__Maploader__

#include <iostream>
#include <fstream>
#include "vector"
#include <SFML/Graphics.hpp>

class   Maploader
{
public:
    Maploader(std::string filepath, int Mapheigth, int Mapwidth);
    ~Maploader();
    std::vector<std::string> getMapVektor(){return mMapVektor;};
    void render(sf::RenderWindow *window);
protected:
private:
    void loadMap();
    
    std::ifstream *pMap;
    std::string mFilepath;
    int mMapheigth, mMapwidth;
    std::string temporaryMap;
    std::vector<std::string> mMapVektor;
    std::vector<std::string>::iterator mMapVektorIterator;
    
    int tempmapx = 0;
    int tempmapy = 0;
    
    
    sf::Texture Tile;

    
    sf::Sprite Tile2sprite;
    
    sf::Texture Weg;
    
    
    sf::Sprite Weg2sprite;

    
};
#endif /* defined(__Nameless__Maploader__) */
