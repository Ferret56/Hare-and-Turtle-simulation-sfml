#include "Food.h"


/*
* @param name  the name of  the food ('apple' for ex.)
*/
Food::Food(sf::Vector2f position, const std::string name, const std::string path_to_the_file) {
	this->foodTexture = new sf::Texture();
	this->foodSprite = new sf::Sprite();
	foodTexture->loadFromFile(path_to_the_file);
	foodSprite->setTexture(*foodTexture);
	this->foodPosition = position;
	this->foodSprite->setPosition(position);
	this->name = name;
	this->path_to_the_image = path_to_the_file;
	
}

Food::~Food() {
	delete this->foodTexture;
	delete this->foodSprite;
}

void Food::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*foodSprite);
}

std::string Food::getName() const {
	return this->name;
}

std::string Food::getAbsolutePathToTheFile() const {
	return this->path_to_the_image;
}

sf::Sprite Food::getSprite() {
	return *foodSprite;
}



