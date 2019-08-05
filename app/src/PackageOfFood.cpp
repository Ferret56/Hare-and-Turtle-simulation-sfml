#include "PackageOfFood.h"
/*
	* @param     foodObj     is a pointer to the Food class whose
	*                                 object we want to generate
	*
	* @param     trackObj    is a pointer to a Track class object
	*                             where we want to generate food
	*
	* @param     amount      is the amount of food we want to generate
	*
	* This constructor calls the 'generateFood' method
*/
PackageOfFood::PackageOfFood(Food* foodObj, Track* trackObj, unsigned int amount) {
	generateFood(foodObj, trackObj, amount);
}
PackageOfFood::~PackageOfFood() {
	for (auto food : packageOfFood)
		delete food.second;
}
/*
	* @param     foodObj     is a pointer to the Food class whose
	*                                 object we want to generate
	*
	* @param     trackObj    is a pointer to a Track class object
	*                             where we want to generate food
	*
	* @param     amount      is the amount of food we want to generate
*/
void PackageOfFood::generateFood(Food* foodObj, Track* trackObj, unsigned int amount) {
	//Generate food in the range from 100......to FinishFlag position - 50px	
	sf::Vector2f  current_food_position = {0,trackObj->getPosition().y + 20};
	for (int i = 0; i < amount; ++i) {
		current_food_position.x = rand() % ((int)trackObj
		                                ->getFinishFlag()
		                                ->getSprite()
		                                ->getPosition().x) - 50 + 100;
		packageOfFood[i] = new Food(current_food_position, foodObj->getName(),
			                             foodObj->getAbsolutePathToTheFile());
	}		
}

void PackageOfFood::draw(sf::RenderWindow* window) {
	for (auto food : packageOfFood)
		window->draw(food.second->getSprite());
}

