#include "Framework.hpp"

//Version 0.0.1


Framework::Framework()
{
    pLog = new Logfile("Logfile.log");
    mAuflösungsBreite = 1680;
    mAuflösungsHöhe = 1456;
   
    clock2.getElapsedTime().asSeconds();
//    mAuflösungsBreite = 1920;
//    mAuflösungsHöhe = 1200;

    pRenderWindow   = new sf::RenderWindow(sf::VideoMode(mAuflösungsBreite,mAuflösungsHöhe,32), "TITLE");
    pLog->writeToFile("Fenster initialisiert");
   
    pRenderWindow->setFramerateLimit(60);
    pMainEvent      = new sf::Event;
    pClock          = new sf::Clock;
    mRun            = true;
    pLog->writeToFile("Restliche Grundfunktionen initialisiert");
 
    Mapheigth       = 100;
    Mapwidth        = 100;
    pMap = new Maploader("Map.txt", mAuflösungsHöhe, mAuflösungsBreite);
   
    pLog->writeToFile("Maphöhe:" + pLog->toString(Mapheigth) +" " + "Mapbreite: " + pLog->toString(Mapwidth) + " " + "Mapgröße: " + pLog->toString((Mapwidth*Mapheigth)));
    
    pPlayer1 = new Player(sf::Vector2f(0,0), mAuflösungsBreite, mAuflösungsHöhe);
    
    ptest = new NPC(*pPlayer1, *Sprites::pNPCHolzfällerSprite, 290,510, "Willfried: Hallo mein, \nName ist Willfried","Willkommen in unserem \nbescheidenen Dorf", "Die Hauser werden\nnoch geliefert");

    pZombie = new Zombie(Sprites::NPCZombieSprite, *pPlayer1, "Zombie", 100,0,200,500, 0, 1000);
    
    pBall = new Fireball<Zombie>(*pPlayer1, *pZombie);
}




Framework::~Framework()
{   pLog->writeToFile("Fensterinstanz geshlossen");
    pPlayer1->closePlayer();
    pLog->closeFile();
    
}



void Framework::Run()
{
    while (mRun)
    {
        Update(mFrameTime);
        EventHandling();
        Render();
        GetFrameTime();
        Quit();
    }
    
}



void Framework::Update(double frametime)
{
    
    pPlayer1->update(mFrameTime);
    ptest->update();
    pZombie->update(mFrameTime);
    pBall->update();
    float currentTime = clock2.restart().asSeconds();
    float fps = 1.f / currentTime ;
    
    //std::cout << fps<< std::endl;
   // std::cout << mFrameTime << std::endl;
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
            delete pMap;
            pMap = nullptr;
            mAuflösungsHöhe = 12*16;
            mAuflösungsBreite = 12*16;
            pMap = new Maploader("Map1.txt", mAuflösungsHöhe, mAuflösungsBreite);
        }
        pPlayer1->setEvent(*pMainEvent);
  
        ptest->setEvent(*pMainEvent);
    }
}



void Framework::Render()
{
    pRenderWindow->clear(sf::Color(0,0,0));
    pMap->render(pRenderWindow);
    ptest->render(pRenderWindow);
    pZombie->render(pRenderWindow);
    pPlayer1->render(pRenderWindow);
    
    pBall->render(pRenderWindow);
   
    pRenderWindow->display();
  
}



float Framework::GetFrameTime()
{
    mFrameTime = pClock->getElapsedTime().asSeconds();
    pClock->restart();


    return mFrameTime;
    
}



void Framework::Quit()
{
    if (!mRun ) {
        pRenderWindow->close();
    }
    
}
