
#ifndef __Nameless__Maploader__
#define __Nameless__Maploader__

#include <iostream>
#include <fstream>
#include "vector"
#include <SFML/Graphics.hpp>
#include "Sprites.h"
class   Maploader : Sprites
{

public:
    Maploader(std::string filepath, int Mapheigth, int Mapwidth);
    ~Maploader();
    std::vector<std::string> getMapVektor(){return mMapVektor;};
    void render(sf::RenderWindow *window);
    void setMap(std::string filepath){mFilepath = filepath;};
    void renderTileLayer(sf::RenderWindow *window);
     void loadMap();
protected:
private:
   
    
    std::ifstream *pMap;
    std::string mFilepath;
    int mMapheigth, mMapwidth;
    std::string temporaryMap;
    std::vector<std::string> mMapVektor;
    std::vector<std::string>::iterator mMapVektorIterator;
    
    int tempmapx = 0;
    int tempmapy = 0;
    
    
  
    

    
};
#endif /* defined(__Nameless__Maploader__) */
