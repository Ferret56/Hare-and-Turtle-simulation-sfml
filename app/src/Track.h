#pragma once
#include <SFML/Graphics.hpp>
#include<String>
#include "Flag.h"
/*
* This class is a treadmill on which the animal runs
*/
class Track {
private:
	sf::Sprite*     trackSprite;
	sf::Texture*    trackTexture;
	sf::Vector2f    trackPosition;
	Flag*           flag;
public:
	Track(const sf::Vector2f position, const std::string path_to_the_file);
	~Track();

	//This function sets the finish by Flag class
	void setFinishFlag(Flag* flag);
	sf::Vector2f getPosition();
	Flag* getFinishFlag();
	void draw(sf::RenderWindow* mainRenderWindow);
};