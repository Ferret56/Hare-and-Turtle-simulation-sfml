#include "Hare.h"
#define MAX_COUNT_OF_THE_FRAMES 8

Hare::Hare(std::string name, sf::Vector2f position, const std::string path_to_the_file) : Animal(name,position, path_to_the_file){
	animationSpeed = 0.01;
	this->animalSprite->setTextureRect(sf::IntRect(0, 0, animalTexture->getSize().x / MAX_COUNT_OF_THE_FRAMES,
		                                                                      animalTexture->getSize().y));
}
Hare::~Hare(){}

 /* Hare's animation function
 *  @param  time   sfml library variable on which animation will depend
*/
void Hare::animate(float time) {
	currentFrame += animationSpeed * time;
	if (currentFrame > MAX_COUNT_OF_THE_FRAMES)
		currentFrame -= MAX_COUNT_OF_THE_FRAMES;
	int rectangle_width = animalTexture->getSize().x / MAX_COUNT_OF_THE_FRAMES;
	int rectangle_height = animalTexture->getSize().y;
	animalSprite->setTextureRect(sf::IntRect(rectangle_width * int(currentFrame),0,
		                                     rectangle_width, rectangle_height));
}

// Hare's random movement
void Hare::getRandomMovement() {
	//generate random number from 1  to 10
	int rnd = rand() % 10 + 1;
	if (rnd <= 5) {
		dir = LEFT;
		speed = 0.03;
	}
	else {
		dir = RIGHT;
		speed = 0.08;
	}
}
