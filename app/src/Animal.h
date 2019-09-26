#pragma once
#include <SFML/Graphics.hpp>
#include<String>
#include "PackageOfFood.h"
/*
* This is an abstract class that represents an animal
* Some methods will be redefined in descendant classes
*/
class Animal {
protected:
	sf::Sprite*                       animalSprite;
	sf::Texture*                      animalTexture;
	sf::Vector2f                      position;
	std::string                       animalName;                // animal's name
	float                             dx;                       // animal's offset
	float                             speed;                   // animal's speed
	float                             animationSpeed;         // animal's animation speed
	enum Directions{RIGHT,LEFT}       dir;                   // animal's direction

	float                             currentFrame;         // current frame image for the animation
	bool                              isBonusActive;       // current status of the bonus
	float                             totalBonusTime;     // bonus time
	float                             currentBonusTime;  // current time
	bool                              isAnimalWin;      // current win status

public:
	Animal(std::string name,sf::Vector2f position, const std::string pathToTheFile);
	virtual ~Animal();
	sf::Sprite* getSprite();
	bool getBonusStatus()const;
	void setWinStatus(bool isWin);
	void activateBonus(bool bonusStatus);
	void increaseCurrentBonusTime(float time);
	float getCurrentBonusTime();
	float getTotalBonusTime();
	std::string getName();
/*
	* @return a logical expression depending on whethere the animal has eaten food
	* @return TRUE if the animal ate food.
	* @param packageOfFood is the all packages of the food in the simulation
	* WARN! Ñhange architecture. Bad implementation
*/
	bool isEatFood(std::vector<PackageOfFood*>* packageOfFood);
	bool isWin();

	/* Animal animation function
	*  @param  time   sfml library variable on which animation will depend
	*/
	virtual void animate(float time)=0;

	//Animal's random movement
	virtual void getRandomMovement()=0;

	//Update Animal's logic
	void update(float time);
	void draw(sf::RenderWindow* mainRenderWindow);

};
