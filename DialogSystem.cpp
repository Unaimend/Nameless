#include "DialogSystem.h"
DialogSystem::DialogSystem(std::string text1, int xpos, int ypos,unsigned int ChraracterSize)
{
    mFont.loadFromFile("sansation.ttf");
    mText.setFont(mFont);
    mText.setString(text1);
    
    mText.setColor(sf::Color::Black);
    mText.setPosition(xpos, ypos - (mText.getScale().y+mText.getCharacterSize()));
    mText.setScale(0.05, 0.05);
    mText.setCharacterSize(ChraracterSize);
    
    mTextBox.setPosition(mText.getPosition().x, mText.getPosition().y);
    mTextBox.setOutlineColor(sf::Color::Blue);
    mTextBox.setOutlineThickness(1.0f);
    mTextBox.setSize(sf::Vector2f(mText.getGlobalBounds().width ,mText.getGlobalBounds().height + 10));
//    std::cout << mText.getGlobalBounds().left << << std::endl;
    
    pAnswerBox = new AnswerBox(150, 500, 1680/2 ,1456-150, sf::Color::Blue);
    
    
         
};

DialogSystem::~DialogSystem(){};

void DialogSystem::update(){
    mTextBox.setPosition(mText.getPosition().x, mText.getPosition().y);
    mTextBox.setSize(sf::Vector2f(mText.getGlobalBounds().width ,mText.getGlobalBounds().height + 10));
    pAnswerBox->update();
    std::cout << pAnswerBox->getAnswer1() << pAnswerBox->getAnswer2()  << pAnswerBox->getAnswer3() << pAnswerBox->getAnswer4() << std::endl;
};
void DialogSystem::render(sf::RenderWindow *window)
{
    window->draw(mTextBox);
    window->draw(mText);
    
  
};


void DialogSystem::answerboxrender(sf::RenderWindow *window)
{
    pAnswerBox->render(*window);
};