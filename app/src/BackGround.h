#pragma once
#include <SFML/Graphics.hpp>
#include<String>
/*
* This is the class that represents the background
*/
class BackGround {
private:
	sf::Sprite*    bgrdSprite;
	sf::Texture*   bgrdTexture;	
public:
	BackGround(const std::string path_to_the_img_file);
	~BackGround();

	void draw(sf::RenderWindow* mainRenderWindow);
};
