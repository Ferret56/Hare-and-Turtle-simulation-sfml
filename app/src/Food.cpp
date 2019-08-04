#include "Food.h"

Food::Food(sf::Vector2f position, const std::string path_to_the_file) {
	this->foodTexture = new sf::Texture();
	this->foodSprite = new sf::Sprite();
	foodTexture->loadFromFile(path_to_the_file);
	foodSprite->setTexture(*foodTexture);
	this->foodPosition = position;
	this->foodSprite->setPosition(position);
}

Food::~Food() {
	delete this->foodTexture;
	delete this->foodSprite;
}

void Food::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*foodSprite);
}


