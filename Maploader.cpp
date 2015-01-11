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
    //loadMap();
    loadMap2();
    
 
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

    
    renderTileLayer(window);
    
}

void Maploader::renderTileLayer(sf::RenderWindow *window)
{

    for(auto it : TileMap)
    {
    Sprites::WasserSprite.setPosition(tempmapx*16, tempmapy*16);
    Sprites::pWegSprite->setPosition(tempmapx*16, tempmapy*16);
    Sprites::pGrasSprite->setPosition(tempmapx*16, tempmapy*16);
    Sprites::pGrasSpriteOL->setPosition(tempmapx*16, tempmapy*16);
    Sprites::pGrasSpriteOBEN->setPosition(tempmapx*16, tempmapy*16);
    Sprites::pGrasSpriteUNTEN->setPosition(tempmapx*16, tempmapy*16);
    Sprites::BlackSprite.setPosition(tempmapx*16, tempmapy*16);
    Sprites::pStraßenSprite->setPosition(tempmapx*16, tempmapy*16);
    if (tempmapx == 20) { //Wenn der Counter == Anzahl der max Tiles bestimmt durch die Mapbreite
        tempmapy++;                 //dann erhöhe die Y-Anzahl um 1 und sezte die X-Anzahl auf 0 damit von
        tempmapx = 0;               //links gezeichnet wird
    }
    if (tempmapy == 20) {    //Wenn du ganz unten bist fange wieder oben an.
        tempmapy = 0;
    }
    
    if(it == "33")
    {
        window->draw(*Sprites::pStraßenSprite);
    }
    else if(it == "78")
    {
        window->draw(*Sprites::pStraßenSprite);
    }
    else if (it == "89")
    {
        window->draw(*Sprites::pStraßenSprite);
    }
    else if (it == "92") {
        window->draw(*Sprites::pStraßenSprite);
    }
    else if (it == "32") {
        window->draw(*Sprites::pStraßenSprite);
    }
    else if (it == "42") {
        window->draw(*Sprites::pStraßenSprite);
    }
    else if(it == "77")
    {
         window->draw(*Sprites::pStraßenSprite);
    }
    tempmapx++;
}


};


void Maploader::loadMap2()
{
        teststream = new std::ifstream("/Users/Thomas/Desktop/TestMaps/TEST2 2.txt");
        
        
        //Könnte bei größeren Maps Probleme verursachen
        for (int it = 0; it < 100; it++)
        {
            *teststream >> tempmap;
            
            
            test.push_back(tempmap);
        }
        
        delete teststream;
        teststream = nullptr;
        
        for (int it = 0;it < test.size(); it++)
        {
            
            if( in_quote(test[it], "height=") && heithcounter)
            {
                // std::cout << it << std::endl;
                for(char it2 : test[it])
                {
                    if (isdigit(it2))
                    {
                        vecheigth.push_back(it2);
                    }
                    
                }
                heithcounter = false;
            }
            
            if( in_quote(test[it], "width=") && widthcounter)
            {
                // std::cout << it << std::endl;
                for(char it2 : test[it])
                {
                    if (isdigit(it2))
                    {
                        vecwidth.push_back(it2);
                    }
                }
                widthcounter =false;
            }
            if( in_quote(test[it], "tilewidth="))
            {
                // std::cout << it << std::endl;
                for(char it2 : test[it])
                {
                    if (isdigit(it2))
                    {
                        //std::cout <<"tilewidth" << it2 << std::endl;
                    }
                }
            }
            if( in_quote(test[it], "tileheight="))
            {
                // std::cout << it << std::endl;
                for(char it2 : test[it])
                {
                    if (isdigit(it2))
                    {
                        // std::cout << "tileheigth="<<it2 << std::endl;
                    }
                }
            }
            if( in_quote(test[it], "data=") && datacounter == 0)
            {
                int counter = 1;
                while (counter < 21)
                {
                    for(char it2 : test[it+counter])
                    {
                        if (it2 != ',')
                        {
                            tilelayer.push_back(it2);
                        }
                    }
                    counter++;
                }
                datacounter++;
                it++;
            }
            
            if( in_quote(test[it], "data=") && datacounter == 1)
            {
                int counter = 1;
                while (counter < 21)
                {
                    for(char it2 : test[it+counter])
                    {
                        if (it2 != ',')
                        {
                            objectlayer.push_back(it2);
                        }
                    }
                    counter++;
                }
                datacounter++;
            }
        }
        
        TileLayerString.append(&tilelayer[0]);
        
        for(int it = 0 ;it < TileLayerString.length()/2; it++)
        {
            
            temptilestring.append(&TileLayerString[tilecounter], 2);
            
            //std::cout << test23 << std::endl;
            TileMap.push_back(temptilestring);
            tilecounter += 2;
            temptilestring.clear();
        }
        
        
        
        ObjectOayerString.append(&objectlayer[0]);
        // IST DAS ARRAY ALS MAX WERT NICHT DER STRING KÖNNTE ZU PROBLEMEN FÜHREN
        //Würde zu Problemen führen falls das Objektlayer zweistellige Zahlen enthält
        for (int it = 0 ; it < objectlayer.size(); it++)
        {
            tempobjlstring.append(&ObjectOayerString[objcounter], 1);
            
            ObjectMap.push_back(tempobjlstring);
            objcounter += 1;
            tempobjlstring.clear();
            
        }
        
        
        heigth.append(&vecheigth[0]);
        width.append(&vecwidth[0]);
        
        iheigth = stoi(heigth);
        iwidth = stoi(width);
       // std::cout << iheigth <<  " "<< iwidth<< std::endl;
        
}




//{
//    for(auto it : mMapVektor)
//    {
//        Sprites::WasserSprite.setPosition(tempmapx*16, tempmapy*16);
//        Sprites::pWegSprite->setPosition(tempmapx*16, tempmapy*16);
//        Sprites::pGrasSprite->setPosition(tempmapx*16, tempmapy*16);
//        Sprites::pGrasSpriteOL->setPosition(tempmapx*16, tempmapy*16);
//        Sprites::pGrasSpriteOBEN->setPosition(tempmapx*16, tempmapy*16);
//        Sprites::pGrasSpriteUNTEN->setPosition(tempmapx*16, tempmapy*16);
//        Sprites::BlackSprite.setPosition(tempmapx*16, tempmapy*16);
//        Sprites::pStraßenSprite->setPosition(tempmapx*16, tempmapy*16);
//        if (tempmapx == mMapwidth/16) { //Wenn der Counter == Anzahl der max Tiles bestimmt durch die Mapbreite
//            tempmapy++;                 //dann erhöhe die Y-Anzahl um 1 und sezte die X-Anzahl auf 0 damit von
//            tempmapx = 0;               //links gezeichnet wird
//        }
//        if (tempmapy == mMapheigth/16) {    //Wenn du ganz unten bist fange wieder oben an.
//            tempmapy = 0;
//        }
//
//        if(it == "0")
//        {
//            window->draw(*Sprites::pStraßenSprite);
//        }
//        else if(it == "1")
//        {
//            window->draw(*Sprites::pStraßenSprite);
//        }
//        else if (it == "2") {
//            window->draw(*Sprites::pWegSprite);
//        }
//        else if (it == "3") {
//            window->draw(*Sprites::pGrasSpriteOL);
//        }
//        else if (it == "4") {
//            window->draw(*Sprites::pGrasSpriteOBEN);
//        }
//        else if (it == "5") {
//            window->draw(*Sprites::pGrasSpriteUNTEN);
//        }
//        else if(it == "-1")
//        {
//            window->draw(Sprites::BlackSprite);
//        }
//        tempmapx++;
//    }


