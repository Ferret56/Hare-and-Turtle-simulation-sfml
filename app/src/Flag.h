#pragma once
#include <SFML/Graphics.hpp>
#include<String>
/*
* This is the class that represents the Flag on the Track
*/
class Flag {
private:
	sf::Sprite*    flagSprite;
	sf::Texture*   flagTexture;

public:
	Flag(sf::Vector2f position, const std::string path_to_the_file);
	~Flag();

	void draw(sf::RenderWindow* mainRenderWindow);
	sf::Sprite* getSprite();
};
