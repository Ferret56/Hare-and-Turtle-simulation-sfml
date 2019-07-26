#include "Turtle.h"

Turtle::Turtle(sf::Vector2f position, const std::string path_to_the_file) : Animal(position, path_to_the_file){
	animationSpeed = 0.005;
}
Turtle::~Turtle() {}

/* Turtle's animation function
*  @param  time   sfml library variable on which animation will depend
*/
void Turtle::animate(float time) {
	currentFrame += animationSpeed * time;
	if (currentFrame > 2)
		currentFrame -= 2;
	animalSprite->setTextureRect(sf::IntRect(112 * int(currentFrame), 0, 112, 75));
}


// Turtle's random movement
void Turtle::getRandomMovement() {
	srand(time(NULL));
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




