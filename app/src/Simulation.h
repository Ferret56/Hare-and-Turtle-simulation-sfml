#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "BackGround.h"
#include "Track.h"
#include "Animal.h"
#include "Turtle.h"
#include "Hare.h"
#include "PackageOfFood.h"
#include "Message.h"
using namespace std;
/*
The main class that will run the simulation 
*/
class Simulation {
private:
	sf::RenderWindow*       mainWindow;     
	sf::Vector2u            mainWindowSize;
	BackGround*             backGround;
	vector<Track*>          tracks;
	vector <Animal*>        animals;
	vector<PackageOfFood*>  foodBasket;

	bool                    isTheSimulationStart;
	bool                    isTheRaceWin;
	sf::Clock clock;     
	float time;

	Message*                 titleMessage;
	Message*                 descriptionMessage;
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
