#include "Framework.hpp"

//Version 0.0.1


Framework::Framework()
{
    pLog = new Logfile("Logfile.log");
    mAuflösungsBreite = 1680;
    mAuflösungsHöhe = 1456;
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
    
    ptest = new NPC();
    }




Framework::~Framework()
{   pLog->writeToFile("Fensterinstanz geshlossen");
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
        pPlayer1->setEvent(*pMainEvent);
    }
}



void Framework::Render()
{
    pRenderWindow->clear(sf::Color(120,120,120));
   
    pMap->render(pRenderWindow);
    ptest->render(pRenderWindow);
    pPlayer1->render(pRenderWindow);
   
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
