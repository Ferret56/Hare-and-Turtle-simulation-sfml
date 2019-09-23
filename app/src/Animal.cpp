#include "Animal.h"
#define BONUS_TIME 500.
/*
* @param  position            animal's position on the track
* @param  path_to_the_file    is the path to the file where the picture is
*/
Animal::Animal(sf::Vector2f position, const std::string path_to_the_file) {
	this->animalTexture = new sf::Texture();
	this->animalSprite = new sf::Sprite();
	this->position = position;
	animalTexture->loadFromFile(path_to_the_file);
	animalSprite->setTexture(*animalTexture);
	animalSprite->setPosition(position);	
	dx = 0;                   // must be redefined in children
	dir = Directions::RIGHT;
	currentFrame = 0;         
	speed = 0.5;            // must be redefined in children
	animationSpeed = 0;    // must be redefined in children
	currentBonusTime = 0;
	totalBonusTime = 0;
	this->isBonusActive = false;
	this->isAnimalWin = false;
}

Animal::~Animal() {
	delete this->animalTexture;
	delete this->animalSprite;
}

bool Animal::getBonusStatus() const {
	return this->isBonusActive;
}

void Animal::activateBonus(bool bonusStatus) {
	this->isBonusActive = bonusStatus;
	if (isBonusActive) {
		totalBonusTime += BONUS_TIME - currentBonusTime;
		currentBonusTime = 0;
		dir = RIGHT;
		speed = 0.20;
	}
	else {
		currentBonusTime = 0;
		totalBonusTime = 0;
	}
}
void Animal::increaseCurrentBonusTime(float time) {
	this->currentBonusTime += time;
}

float Animal::getCurrentBonusTime() { return this->currentBonusTime; }

float Animal::getTotalBonusTime() { return this->totalBonusTime; }


/*
	* @return a logical expression depending on whethere the animal has eaten food
	* @return TRUE if the animal ate food.
	* @param packageOfFood is the all packages of the food in the simulation
	* WARN! Ñhange architecture.Bad implementation
*/
bool Animal::isEatFood(std::vector<PackageOfFood*>* packageOfFood) {
	for (int i(0); i < packageOfFood->size(); ++i) {
		std::map<unsigned int, Food*>::iterator mapIt = (*packageOfFood).at(i)->getMapFood()->begin(); // map food iterator
		for (; mapIt != (*packageOfFood).at(i)->getMapFood()->end(); ++mapIt) {
			if (this->animalSprite->getGlobalBounds().intersects((*mapIt).second->getSprite().getGlobalBounds())) {
				  // remove the food from the map that was eaten
			     //                    WARN!
				//              Bad implementation
				delete (*mapIt).second;
				(*packageOfFood).at(i)->getMapFood()->erase((*mapIt).first);
				return true;
			}
		}
	}
	return false;
}

bool Animal::isWin() { return this->isAnimalWin; }


void Animal::update(float time) {
	switch (dir) {
	     case RIGHT:
		     dx = speed;
		     break;
	     case LEFT:
		     dx = -speed;
		     break;
	}
	position.x += dx * time;
	if (position.x < 0)
		position.x = 0;

	animalSprite->setPosition(position.x, position.y);
}

void Animal::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*animalSprite);
}
