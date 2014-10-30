#include "Maploader.h"
#include <Logfile.h>

Maploader::Maploader(std::string filepath, int Mapheigth, int Mapwidth)
{
    mMapheigth          = Mapheigth;
    mMapwidth           = Mapwidth;
    mFilepath           = filepath;
    temporaryMap        = "0";
    mMapVektorIterator  = mMapVektor.begin();
    pMap                = new std::ifstream(mFilepath);
    loadMap();
    
 
};

Maploader::~Maploader()
{
    delete pMap;
    pMap = nullptr;
};

void Maploader::loadMap()
{
    for (int it = 0; it < mMapheigth/16 * mMapwidth/16; it++)
    {
        *pMap >> temporaryMap;
        mMapVektor.push_back(temporaryMap);
    }
    
};

void Maploader::render(sf::RenderWindow *window)
{
    if (grasscolor < 70) {
        grasscolor = 255;
    }
    pGrasSprite->setColor(sf::Color(255,255,255,grasscolor));
    WasserSprite.setColor(sf::Color(255,255,255,grasscolor));
    grasscolor = grasscolor - 0.01;
    
    renderTileLayer(window);
    
}

void Maploader::renderTileLayer(sf::RenderWindow *window)
{
    for(auto it : mMapVektor)
    {
        Sprites::WasserSprite.setPosition(tempmapx*16, tempmapy*16);
        Sprites::pWegSprite->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSprite->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSpriteOL->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSpriteOBEN->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSpriteUNTEN->setPosition(tempmapx*16, tempmapy*16);
        Sprites::BlackSprite.setPosition(tempmapx*16, tempmapy*16);
        if (tempmapx == mMapwidth/16) { //Wenn der Counter == Anzahl der max Tiles bestimmt durch die Mapbreite
            tempmapy++;                 //dann erhöhe die Y-Anzahl um 1 und sezte die X-Anzahl auf 0 damit von
            tempmapx = 0;               //links gezeichnet wird
        }
        if (tempmapy == mMapheigth/16) {    //Wenn du ganz unten bist fange wieder oben an.
            tempmapy = 0;
        }
   
        if(it == "0")
        {
            window->draw(*Sprites::pGrasSprite);
        }
        else if(it == "1")
        {
            window->draw(Sprites::WasserSprite);
        }
        else if (it == "2") {
            window->draw(*Sprites::pWegSprite);
        }
        else if (it == "3") {
            window->draw(*Sprites::pGrasSpriteOL);
        }
        else if (it == "4") {
            window->draw(*Sprites::pGrasSpriteOBEN);
        }
        else if (it == "5") {
            window->draw(*Sprites::pGrasSpriteUNTEN);
        }
        else if(it == "-1")
        {
            window->draw(Sprites::BlackSprite);
        }
        tempmapx++;
    }
};


//    for (int it2 = 0; it2 < mMapheigth; it2++)
//    {
//        for (int it = 0; it < mMapwidth; it++)
//        {
//
////            if ((*mMapVektorIterator) == "3")
////            {
////                Blumen01Sprite.setPosition(mMapwidth, mMapheigth);
////                window->draw(Blumen01Sprite);
////            }
////            if ((*mMapVektorIterator) == "2")
////            {
////                Weg_01Sprite.setPosition(mMapwidth, mMapheigth);
////
////                window->draw(Weg_01Sprite);
////
////            }
////            if ((*mMapVektorIterator) == "1")
////            {
////                Wassersprite.setPosition(mMapwidth, mMapheigth);
////                //KOLLISIONSVEKTOR WIRD MIT DEM WASSERTILE GELADEN
////                //                    sf::RectangleShape *rec = new sf::RectangleShape;
////                //                    rec->setSize(sf::Vector2f(16,16));
////                //                    rec->setPosition(xpos, ypos);
////                //                    rec->setFillColor(sf::Color(255,255,255,255));
////                //                    kollision.push_back(*rec);
////                window->draw(Wassersprite);
////
////            }
//            if ((*mMapVektorIterator) == "0")
//            {
//                Tile2sprite.setPosition(mMapwidth, mMapheigth);
//                window->draw(Tile2sprite);
//            }
//
//
//            *mMapVektorIterator++;
//            mMapwidth = mMapwidth +16;
//        }
//        mMapwidth = 0;
//        mMapheigth = mMapheigth + 16;
//    }
//    mMapheigth  = 0;
