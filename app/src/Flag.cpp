#include "Flag.h"
/*
* @param  position            position finish Flag on the track
* @param  path_to_the_file    is the path to the file where the picture is
*/
Flag::Flag(sf::Vector2f position, const std::string path_to_the_file) {
	this->flagTexture = new sf::Texture();
	this->flagSprite = new sf::Sprite();
	flagTexture->loadFromFile(path_to_the_file);
	flagSprite->setTexture(*flagTexture);
	flagSprite->setPosition(position);
}

Flag::~Flag() {
	delete this->flagTexture;
	delete this->flagSprite;
}

void Flag::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*flagSprite);
}

sf::Sprite* Flag::getSprite() {
	return this->flagSprite;
}
