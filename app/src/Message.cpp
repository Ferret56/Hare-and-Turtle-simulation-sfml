#include "Message.h"

Message::Message() {
	Message::Message("default", R"(app/resources/fonts/TSSSF.otf)", 50);
}


Message::Message(std::string message, std::string pathToTheFont, unsigned int size) {	
	this->message = message;
	font = new sf::Font();
	font->loadFromFile(pathToTheFont);
	text = new sf::Text(message, *font, size);
	text->setColor(sf::Color::White);
}


Message::~Message() {
	delete this->font;
	delete this->text;
}

void Message::draw(sf::RenderWindow* window) {
	window->draw(*text);
}

void Message::setPosition(float x, float y) {
	text->setPosition(x, y);
}



