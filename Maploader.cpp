#include "Maploader.h"
#include <Logfile.h>

Maploader::Maploader(std::string filepath, int Mapheigth, int Mapwidth)
{
    mMapheigth = Mapheigth;
    mMapwidth = Mapwidth;
    
    mMapVektorIterator = mMapVektor.begin();
    mFilepath = filepath;
    temporaryMap = "0";
    pMap = new std::ifstream(mFilepath);
    loadMap();
    
 
};

Maploader::~Maploader(){};

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
   
    for(auto it : mMapVektor)
    {
        
       
        Sprites::WasserSprite.setPosition(tempmapx*16, tempmapy*16);
        Sprites::pWegSprite->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSprite->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSpriteOL->setPosition(tempmapx*16, tempmapy*16);
        Sprites::pGrasSpriteOBEN->setPosition(tempmapx*16, tempmapy*16);
        if (tempmapx == mMapwidth/16) {
            tempmapy++;
            tempmapx = 0;
        }
        if (tempmapy == mMapheigth/16) {
            tempmapy = 0;
        }
        if(it == "0")
        {
            window->draw(*Sprites::pGrasSprite);
        }
        if(it == "1")
        {
            window->draw(Sprites::WasserSprite);
        }
        if (it == "2") {
            window->draw(*Sprites::pWegSprite);
        }
        if (it == "3") {
            window->draw(*Sprites::pGrasSpriteOL);
        }
        if (it == "4") {
            window->draw(*Sprites::pGrasSpriteOBEN);
        }
        
      
         tempmapx++;
        
        
    }
   
    
}





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
