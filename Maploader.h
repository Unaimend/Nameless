
#ifndef __Nameless__Maploader__
#define __Nameless__Maploader__

#include <iostream>
#include <fstream>
#include "vector"
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <type_traits>
#include "Tiles.h"
#include "Player.h"
class   Maploader : Sprites
{

public:
    Maploader(std::string filepath, int Mapheigth, int Mapwidth, Player& player);
    ~Maploader();
    std::vector<std::string> getMapVektor(){return mMapVektor;};
    void render(sf::RenderWindow *window);
    void setMap(std::string filepath){mFilepath = filepath;};
    void renderTileLayer(sf::RenderWindow *window);
    void loadMap();
    void loadMap2();
    template<typename Container>
    bool in_quote(const Container& cont, const std::string& s)
    {
        return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
    }
private:
    std::ifstream *pMap;
    std::string mFilepath;
    std::string temporaryMap;
    std::vector<std::string> mMapVektor;
    std::vector<std::string>::iterator mMapVektorIterator;
    int mMapheigth, mMapwidth;
    int tempmapx = 1;   //ER FUNKTIONIERT BEI1 , beim alten Loader
    int tempmapy = 0;   //FUNKTIONIERT bei 0,beim alten Loader

    float grasscolor = 255;
    
    
    std::ifstream *teststream;
    bool widthcounter = true, heithcounter= true; // Sort dafür das width und height nur einmal gelesen werden
    std::string TileLayerString;                    //Strings die die Tiledaten/objektdaten an einem Stück enthalten
    std::string ObjectOayerString;
    int datacounter = 0;
    
    std::vector<std::string> test; //DateiVektor hält die Map die von Tiled ausgespuckt wird.
    std::string tempmap;            //Temporärer String der benutzt wird um die Daten vom ifstream in Vektor zu bekommen
    std::vector<char> tilelayer;      //Hält die Tiledaten in einzelnen Arrayplätzen, aber als char, also einzeln
    std::vector<char> objectlayer;  //Hält die ObjektDaten in einzelnen Arrayplätzen, aber als char, also einzeln
    std::string tempobjlstring;         //Die String die die eizelnen Charplätze zusammenfügen um sie in einen Vektor verfrachten zu können
    std::string temptilestring;
    int tilecounter = 0;
    int objcounter = 0;
    std::vector<char> vecheigth, vecwidth;  //Enhält die Höhe und Breite an einzelnen Arrayplätzen, um sie an einen String anhängen zu können.
    std::string heigth, width;              //Höhe und Breite der Map, wir später zu Int konvertiert.
    std::vector<std::string> TileMap;       //Enthält die fertige Map, die bereit zum rendern ist.
    std::vector<std::string> ObjectMap;
    std::vector<Tile*> mNewVector;
    Player* mPlayer;
    
    std::string nwstring = "";
    int iheigth;
    int iwidth;
    
 
};
#endif /* defined(__Nameless__Maploader__) */
