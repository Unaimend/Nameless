#include "Sprites.h"

Sprites::Sprites()
{
    pLog = new Logfile("Texture.log");
    
    if(WasserTexture.loadFromFile("wasser.png"))
        pLog->writeToFile("Wassertextur geladen");
    if(WegTexture.loadFromFile("weg01.png"))
        pLog->writeToFile("Wegtextur geladen");
    if(PlayerTexture.loadFromFile("Character.png"))
        pLog->writeToFile("Spielertextur geladen");
    if(InventoryTexture.loadFromFile("inventar v01.png"))
        pLog->writeToFile("Inventartextur geladen");
    if(TileSet_ATexture.loadFromFile("Tileset A.png"))
        pLog->writeToFile("Tileset A geladen");
    if(NPCHolzfällerTexture.loadFromFile("Holzfäller.png"))
        pLog->writeToFile("Holfäller geladen");
    if(BlackTexture.loadFromFile("BlackTile.png"))
        pLog->writeToFile("BlackTile geladen");
    if(NPCZombieTexture.loadFromFile("Opi.png"))
        pLog->writeToFile("Opi geladen");
    
    if(mStraßenTexture.loadFromFile("Straße.png"))
        pLog->writeToFile("Straßee geladen");
    mWohnBlock_01.loadFromFile("/Users/Thomas/Google Drive/Game/Grafiken/Objekte/Wohnblock -1.png");
    mBetonTexture.loadFromFile("Straße.png");
    
    NPCZombieSprite.setTexture(NPCZombieTexture);
    BlackSprite.setTexture(BlackTexture);
    WasserSprite.setTexture(WasserTexture);
    mSubRect.left   = 32;
    mSubRect.top    = 64;
    mSubRect.width  = 32;
    mSubRect.height = 32;
    pPlayerSprite   = new sf::Sprite(PlayerTexture, mSubRect );
    
    InventorySprite.setTexture(InventoryTexture);
    mSubRect.left   = 16; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 16;
    mSubRect.width  = 16;
    mSubRect.height = 16;
    pWegSprite      = new sf::Sprite(TileSet_ATexture, mSubRect);
    
    mSubRect.left   = 0; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 48;
    mSubRect.width  = 16;
    mSubRect.height = 16;
    
    pGrasSprite     = new sf::Sprite(TileSet_ATexture, mSubRect);
    
    //100Sieht gut aus
    
    mSubRect.left   = 0; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 0;
    mSubRect.width  = 16;
    mSubRect.height = 16;
    pGrasSpriteOL   = new sf::Sprite(TileSet_ATexture, mSubRect);
    
    mSubRect.left   = 16; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 0;
    mSubRect.width  = 16;
    mSubRect.height = 16;
    pGrasSpriteOBEN = new sf::Sprite(TileSet_ATexture, mSubRect);
    
    mSubRect.left   = 16; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 32;
    mSubRect.width  = 16;
    mSubRect.height = 16;
    pGrasSpriteUNTEN = new sf::Sprite(TileSet_ATexture, mSubRect);
    
    mSubRect.left   = 32; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 64;
    mSubRect.width  = 32;
    mSubRect.height = 32;
    pNPCHolzfällerSprite = new sf::Sprite(NPCHolzfällerTexture, mSubRect);
  
    mSubRect.left   = 32; // of course, you'll have to fill it in with the right values...
    mSubRect.top    = 32;
    mSubRect.width  = 32;
    mSubRect.height = 32;
    
    pStraßenSprite = new sf::Sprite(mStraßenTexture, mSubRect);
   
    mSubRect.left = 16;
    mSubRect.top = 0;
    mSubRect.width = 16;
    mSubRect.height = 16;
    
    pBeton = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.left = 0;
    mSubRect.top = 32;
    pMittelSauberSprite = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.left = 48;
    mSubRect.top = 80;
    pBürgerSteigObenMitte = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.left = 48;
    mSubRect.top = 16;
    pBürgerSteigUntenMitte = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.left = 80;
    mSubRect.top = 0;
    pKreuzung = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.top = 0;
    mSubRect.left = 0;
    mSubRect.width = 130;
    mSubRect.height = 160;
    
    pWohnBlock_01 = new sf::Sprite(mWohnBlock_01, mSubRect);
    
    mSubRect.top = 48;
    mSubRect.left = 16;
    mSubRect.width = 16;
    mSubRect.height = 16;
    
    pBürgerSteigLinks = new sf::Sprite(mBetonTexture, mSubRect);
    mSubRect.top = 48;
    mSubRect.left = 80;
    mSubRect.width = 16;
    mSubRect.height = 16;
    
    pBürgerSteigRechts = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.top = 0;
    mSubRect.left = 64;
    mSubRect.width = 16;
    mSubRect.height = 16;
    
    pMittelHochSauberSprite = new sf::Sprite(mBetonTexture, mSubRect);
    
    mSubRect.top = 64;
    mSubRect.left = 80;
    mSubRect.width = 16;
    mSubRect.height = 16;
    
    pKurveLinks = new sf::Sprite(mBetonTexture, mSubRect);
    
    
    mSubRect.top = 64;
    mSubRect.left = 16;
    mSubRect.width = 16;
    mSubRect.height = 16;
    
    pKurveRechts = new sf::Sprite(mBetonTexture, mSubRect);
    
    
    pLog->writeToFile("Alle Sprites geladen");
    pLog->closeFile();
   
}

Sprites::~Sprites()
{
};