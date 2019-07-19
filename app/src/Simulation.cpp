#include "Simulation.h"
#pragma once
/*
* Standart constructor for the Simulation class.
* @param    main_window_size        is the  size of the main simulation window
* @param    full_simulation_name    is the name of the simulation
*/
Simulation::Simulation(sf::Vector2u main_window_size, const string full_simulation_name) {
	this->mainWindowSize.x = main_window_size.x;
	this->mainWindowSize.y = main_window_size.y;
	this->mainWindow = new sf::RenderWindow(sf::VideoMode(main_window_size.x, main_window_size.y), full_simulation_name);
	this->backGround = new BackGround("app/resources/img/background/background.png");

	//Generate the animal's tracks//
	tracks = {
		 new Track(sf::Vector2f(0, 220),"app/resources/img/track/track.png"),
		 new Track(sf::Vector2f(0, 420), "app/resources/img/track/track.png")
	};

	//Generate the finish flags on the animal's tracks//
	for (Track* track : tracks)
		track->setFinishFlag(new Flag(sf::Vector2f(track->getPosition().x + mainWindowSize.x-100,
			                                        track->getPosition().y - 50),
			                                        "app/resources/img/finish/flag.png"));
}

/*
* Standart constructor for the Simulation class
*/
Simulation::~Simulation() {
	delete this->mainWindow;
	delete this->backGround;
	for (Track* track : tracks)
		delete track;

}
/*
* This function handles all events
*/
void Simulation::processEvents() {
	sf::Event event;
	while (this->mainWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			this->mainWindow->close();
	}
}
/*
*This function updates the game logic
*/
void Simulation::update() {

}
/*
* This function draws objects on the screen
*/
void Simulation::render() {
	this->mainWindow->clear();
	this->backGround->draw(mainWindow);
	for (Track* track : tracks) {
		track->draw(mainWindow);
		track->getFinishFlag()->draw(mainWindow);
	}
	this->mainWindow->display();
}
/*
* This function starts the simulation
*/
void Simulation::run() {
	while (this->mainWindow->isOpen()) {
		processEvents();
		update();
		render();
	}
}




