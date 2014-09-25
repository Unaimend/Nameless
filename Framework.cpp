#include "Framework.hpp"

//Version 0.0.1


Framework::Framework()
{
    pLog = new Logfile("Logfile.log");
    mAuflösungsBreite = 1680;
    mAuflösungsHöhe = 1456;
    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(mAuflösungsBreite,mAuflösungsHöhe,32), "TITLE");
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    pMap            = new Maploader("Map.txt", mAuflösungsHöhe, mAuflösungsBreite);
    pNPC_01         = new NPC(mPlayer1, *Sprites::pNPCHolzfällerSprite, 290,510, "Willfried: Hallo mein, \nName ist Willfried","Willkommen in unserem \nbescheidenen Dorf",                                         "Die Hauser werden\nnoch geliefert");
    pZombie         = new Zombie(Sprites::NPCZombieSprite, mPlayer1, "Zombie", 100,0,200,500, 0, 1000);
    mRun            = true;
    Mapheigth       = 100;
    Mapwidth        = 100;
    
    
    pLog->writeToFile("Fenster und Restliche Grundfunktionen initialisiert");
    
    mPlayer1.setAuflösungsBreite(mAuflösungsBreite);
    mPlayer1.setAuflösungsHöhe(mAuflösungsHöhe);
    mPlayer1.setStartPos(sf::Vector2f(0,0));
    
    mPlayerMagicSystem.setPlayer(mPlayer1);
    mPlayerMagicSystem.setMagicka(mPlayer1.getMagicka());
    
    clock2.getElapsedTime().asSeconds();
    
   
    pLog->writeToFile("Maphöhe:" + pLog->toString(Mapheigth) +" " + "Mapbreite: " + pLog->toString(Mapwidth) + " " + "Mapgröße: " + pLog->toString((Mapwidth*Mapheigth)));  

    //TESTCODE
    mView.setSize(sf::Vector2f(mAuflösungsBreite, mAuflösungsHöhe));
    mView.setViewport(sf::FloatRect(0.0f, 0, 1.0f, 1.0f));
    mView.zoom(0.25);
    mFixed.setSize(sf::Vector2f(mAuflösungsBreite, mAuflösungsHöhe));
    
    pItemManager = new ItemManger(*pPlayerPtr);
    


}


Framework::~Framework()
{   pLog->writeToFile("Fensterinstanz geshlossen");
    delete pRenderWindow;
    pRenderWindow = nullptr;
    pLog->closeFile();
}



void Framework::Run()
{
    while (mRun)
    {
        
        std::cout <<"" << std::endl;
        Update(mFrameTime);
        EventHandling();
        Render();
        getFrameTime();
        Quit();
    }
}



void Framework::Update(double frametime)
{
    mPlayer1.update(mFrameTime);
    
    pNPC_01->update();
    pZombie->update(mFrameTime);
    mPlayerMagicSystem.update(mFrameTime);
    pItemManager->update(pPlayerPtr, mFrameTime);
    mView.setCenter(mPlayer1.getPlayerSpritePosX(), mPlayer1.getPlayerSpritePosY());
    mFixed.setCenter(mAuflösungsBreite/2, mAuflösungsHöhe/2  );
}



void Framework::EventHandling()
{
    while (pRenderWindow->pollEvent(*pMainEvent))
    {
        if (pMainEvent->type == sf::Event::Closed || (pMainEvent->type == sf::Event::KeyPressed   && pMainEvent->key.code == sf::Keyboard::Escape))
        {
            mRun = false;
        }
        if (pMainEvent->type == sf::Event::Closed || (pMainEvent->type == sf::Event::KeyPressed   && pMainEvent->key.code == sf::Keyboard::T))
        {
            loadMap();
        }
        if (pMainEvent->type == sf::Event::KeyPressed   && pMainEvent->key.code == sf::Keyboard::H)
        {
            mPlayerMagicSystem.cast(mPlayer1);
        }
        
       

        pItemManager->eventHandling(*pMainEvent);
        mPlayer1.eventHandling(*pMainEvent);
        pNPC_01->setEvent(*pMainEvent);
        mPlayerMagicSystem.setSpell(*pMainEvent);
    }
}



void Framework::Render()
{
    
   
    pRenderWindow->clear(sf::Color(0,0,0));
    pMap->render(pRenderWindow);
    pNPC_01->render(pRenderWindow);
    pZombie->render(pRenderWindow);
    mPlayerMagicSystem.render(*pRenderWindow);
    pItemManager->render(pRenderWindow);
    mPlayer1.render(pRenderWindow);
    pRenderWindow->setView(mFixed);
   
    pItemManager->fixrender(pRenderWindow);
    pNPC_01->nonfixrender(pRenderWindow);
    pRenderWindow->setView(mView);
    
   // pTest->render(pRenderWindow);
  
    pRenderWindow->display();
}

float Framework::getFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();
    return mFrameTime;
}

float Framework::getFPS()
{
    float currentTime = clock2.restart().asSeconds();
    float fps = 1.f / currentTime ;
    std::cout << fps<< std::endl;
    return fps;
};

void Framework::loadMap()
{
    delete pMap;
    pMap = nullptr;
    mAuflösungsHöhe = 12*16;
    mAuflösungsBreite = 12*16;
    pMap = new Maploader("Map1.txt", mAuflösungsHöhe, mAuflösungsBreite);
};

void Framework::Quit()
{
    if (!mRun ) {
        pRenderWindow->close();
    }
    
}
