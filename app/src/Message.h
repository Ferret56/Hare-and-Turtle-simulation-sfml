#pragma once
#include <SFML/Graphics.hpp>
/*
* Instances of this class are text on screen
*/
class Message {
private:
	sf::Font*     font;
	sf::Text*     text;
	std::string   message;
public:
	Message();
	Message(std::string message, std::string pathToTheFont, unsigned int size);
	~Message();
	void draw(sf::RenderWindow* window);
	void setPosition(float x, float y);
};
