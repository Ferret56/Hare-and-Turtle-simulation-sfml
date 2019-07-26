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
	float                             dx;         // animal's offset
	float                             speed;     // animal's speed
	enum Directions{RIGHT,LEFT}       dir;      // animal's direction

	float                             currentFrame; // current frame image for the animation

public:
	Animal(sf::Vector2f position, const std::string path_to_the_file);
	virtual ~Animal();

	void draw(sf::RenderWindow* mainRenderWindow);

};
