#include "Animal.h"
/*
* @param  position            animal's position on the track
* @param  path_to_the_file    is the path to the file where the picture is
*/
Animal::Animal(sf::Vector2f position, const std::string path_to_the_file) {
	this->animalTexture = new sf::Texture();
	this->animalSprite = new sf::Sprite();
	animalTexture->loadFromFile(path_to_the_file);
	animalSprite->setTexture(*animalTexture);
	animalSprite->setPosition(position);
	dx = 0;                   // must be redefined in children
	dir = Directions::RIGHT;
	currentFrame = 0;         
	speed = 0.5;            // must be redefined in children
	animationSpeed = 0;    // must be redefined in children
}

Animal::~Animal() {
	delete this->animalTexture;
	delete this->animalSprite;
}

void Animal::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*animalSprite);
}
