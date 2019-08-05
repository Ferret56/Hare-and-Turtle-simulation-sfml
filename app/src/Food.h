#pragma once
#include <SFML/Graphics.hpp>
#include<String>
/*
* This class represents different food (in the amount of one piece)
*                               FOR EXAMPLE:
*                           'Apple'  for turtule
*                           'Carrot' for hare
* Class is not abstract
* Designed to facilitate and understand simulation logic
*/
class Food {
protected:
	sf::Sprite*    foodSprite;
	sf::Texture*   foodTexture;
	sf::Vector2f   foodPosition;
	std::string    name;                  //the name of the food('apple' for ex.)
	std::string    path_to_the_image;    //the path to the image file
public:
	Food(sf::Vector2f position, const std::string name, const std::string path_to_the_file);	
	~Food();
	void draw(sf::RenderWindow* mainRenderWindow);
	std::string getName() const;
	std::string getAbsolutePathToTheFile() const;
	sf::Sprite  getSprite();
};

