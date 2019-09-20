#pragma once
#include <SFML/Graphics.hpp>
#include<String>
#include "Food.h"
#include "Track.h"
/*
* This class represents a package of several types of food
* A package of food (several pieces) is on a certain animal's path
*/
//start!
class PackageOfFood{
private:
	//std::map of several types of food
	//               WHERE:
	//unsigned int  is the serial number of the food
	//Food*         is the food itself
	std::map<unsigned int, Food*>    packageOfFood;
public:
	/*
	* @param     foodObj     is a pointer to the Food class whose
	*                                 object we want to generate
	*
	* @param     trackObj    is a pointer to a Track class object
	*                             where we want to generate food
	*
	* @param     amount      is the amount of food we want to generate
	*/	
	PackageOfFood(Food* foodObj, Track* trackObj, unsigned int amount);
	~PackageOfFood();
	/*
	* @param     foodObj     is a pointer to the Food class whose
	*                                 object we want to generate
	*
	* @param     trackObj    is a pointer to a Track class object
	*                             where we want to generate food
	*
	* @param     amount      is the amount of food we want to generate
	*/
	void generateFood(Food* foodObj, Track* trackObj, unsigned int amount);
	void draw(sf::RenderWindow* window);
	

};

