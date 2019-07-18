#include "BackGround.h"
/*
* @param  path_to_the_img_file is the path to the file where the picture is
*/
BackGround::BackGround(const std::string path_to_the_img_file) {
	this->bgrdTexture = new sf::Texture();
	this->bgrdSprite = new sf::Sprite();
	bgrdTexture->loadFromFile(path_to_the_img_file);
	bgrdSprite->setTexture(*bgrdTexture);
}

BackGround::~BackGround() {
	delete this->bgrdSprite;
	delete this->bgrdTexture;
}
/*
* Background drawing function
* @param mainRenderWindow is a pointer to the window in which the object will be drawn
*/
void BackGround::draw(sf::RenderWindow* mainRenderWindow) {
	mainRenderWindow->draw(*bgrdSprite);
}

