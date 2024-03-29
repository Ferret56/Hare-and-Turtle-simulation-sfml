#include "Track.h"

/*
* @param   position is the       position animal's track on the screen
* @param   path_to_the_file      is the path to the file where the picture is
*/
Track::Track(const sf::Vector2f position, const std::string path_to_the_file) {
	this->trackTexture = new sf::Texture();
	this->trackSprite = new sf::Sprite();
	this->flag = nullptr;
	trackTexture->loadFromFile(path_to_the_file);
	trackSprite->setTexture(*trackTexture);
	trackSprite->setPosition(position);
	this->trackPosition = position;
}

Track::~Track() {
	delete this->trackTexture;
	delete this->trackSprite;
	delete this->flag;
}

void Track::setFinishFlag(Flag* flag) {
	this->flag = flag;
}

sf::Vector2f Track::getPosition() {
	return trackSprite->getPosition();
}


Flag* Track::getFinishFlag() {
	return this->flag;
}


void Track::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*trackSprite);
}


