#pragma once
#include <SFML/Graphics.hpp>
#include<String>
/*
* This is an abstract class that represents an animal
* Some methods will be redefined in descendant classes
*/
class Animal {
protected:
	sf::Sprite*                       animalSprite;
	sf::Texture*                      animalTexture;
	sf::Vector2f                      position;
	float                             dx;                   // animal's offset
	float                             speed;               // animal's speed
	float                             animationSpeed;     // animal's animation speed
	enum Directions{RIGHT,LEFT}       dir;               // animal's direction

	float                             currentFrame;     // current frame image for the animation
	bool                              isBonusActive;   // current status of the bonus

public:
	Animal(sf::Vector2f position, const std::string path_to_the_file);
	virtual ~Animal();
	bool getBonusStatus()const;
	void activateBonus(bool bonusStatus);

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
