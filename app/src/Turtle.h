#pragma once
#include <SFML/Graphics.hpp>
#include<String>
#include "Animal.h"

/*
* This class inherits the animal abstract class
*/
class Turtle : public Animal {
public:
	Turtle(sf::Vector2f position, const std::string path_to_the_file);
	~Turtle();


	/* Turtle's animation function
	*  @param  time   sfml library variable on which animation will depend
	*/
	virtual void animate(float time) override;
};
