#include "Track.h"

/*
* @param   position is the       position animal's track on the screen
* @param   path_to_the_file      is the path to the file where the picture is
*/
Track::Track(const sf::Vector2f position, const std::string path_to_the_file) {
	this->trackTexture = new sf::Texture();
	this->trackSprite = new sf::Sprite();
	trackTexture->loadFromFile(path_to_the_file);
	trackSprite->setTexture(*trackTexture);
	trackSprite->setPosition(position);
}

Track::~Track() {
	delete this->trackTexture;
	delete this->trackSprite;
}

void Track::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*trackSprite);
}


