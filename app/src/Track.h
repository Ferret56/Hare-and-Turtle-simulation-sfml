#pragma once
#include <SFML/Graphics.hpp>
#include<String>
/*
* This class is a treadmill on which the animal runs
*/
class Track {
private:
	sf::Sprite*     trackSprite;
	sf::Texture*    trackTexture;
	sf::Vector2f    trackPosition;
public:
	Track(const sf::Vector2f position, const std::string path_to_the_file);
	~Track();

	void draw(sf::RenderWindow* mainRenderWindow);

};