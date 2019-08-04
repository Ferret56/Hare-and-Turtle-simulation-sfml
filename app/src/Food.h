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
public:
	Food(sf::Vector2f position, const std::string path_to_the_file);
	~Food();
	void draw(sf::RenderWindow* mainRenderWindow);
};

