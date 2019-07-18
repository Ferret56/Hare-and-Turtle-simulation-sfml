#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
/*
The main class that will run the simulation 
*/
class Simulation {
private:
	sf::RenderWindow* mainWindow;     
	sf::Vector2u mainWindowSize;

public:
	 Simulation(sf::Vector2u main_window_size,const string full_simulation_name);
	 ~Simulation();
	//Run the simulation
	void run();

private:
	void processEvents();
	void update();
	void render();
};
