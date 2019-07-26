#include "Hare.h"

Hare::Hare(sf::Vector2f position, const std::string path_to_the_file) : Animal(position, path_to_the_file){
	animationSpeed = 0.01;
}
Hare::~Hare(){}

 /* Hare's animation function
 *  @param  time   sfml library variable on which animation will depend
*/
void Hare::animate(float time) {
	currentFrame += animationSpeed * time;
	if (currentFrame > 8)
		currentFrame -= 8;
	animalSprite->setTextureRect(sf::IntRect(75 * int(currentFrame), 0, 75, 89));
}
