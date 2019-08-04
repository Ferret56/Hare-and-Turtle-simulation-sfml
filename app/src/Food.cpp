#include "Food.h"


/*
* @param name  the name of  the food ('apple' for ex.)
*/
Food::Food(sf::Vector2f position, const std::string path_to_the_file, const std::string name) {
	this->foodTexture = new sf::Texture();
	this->foodSprite = new sf::Sprite();
	foodTexture->loadFromFile(path_to_the_file);
	foodSprite->setTexture(*foodTexture);
	this->foodPosition = position;
	this->foodSprite->setPosition(position);
	this->name = name;
	
}

Food::~Food() {
	delete this->foodTexture;
	delete this->foodSprite;
}

void Food::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*foodSprite);
}

std::string Food::getname() const {
	return this->name;
}


