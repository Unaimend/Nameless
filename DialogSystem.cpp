#include "DialogSystem.h"
DialogSystem::DialogSystem(std::string text, int xpos, int ypos,unsigned int ChraracterSize)
{
    mFont.loadFromFile("sansation.ttf");
    mText.setFont(mFont);
    mText.setString(text);
    
    mText.setColor(sf::Color::Black);
    mText.setPosition(xpos, ypos - (mText.getScale().y+mText.getCharacterSize()));
    mText.setScale(0.08, 0.08);
    mText.setCharacterSize(ChraracterSize);
    

};

DialogSystem::~DialogSystem(){};

void DialogSystem::render(sf::RenderWindow *window)
{
    window->draw(mText);
};