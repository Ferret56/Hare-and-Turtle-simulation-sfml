#include "Simulation.h"
#include"PackageOfFood.h"
#pragma once
#define    BACKGROUND_PATH    "app/resources/img/background/background.png"
#define    TRACK_PATH         "app/resources/img/track/track.png"
#define    FLAG_PATH          "app/resources/img/finish/flag.png"
#define    TURTLE_PATH        "app/resources/img/animals/turtle.png"
#define    HARE_PATH          "app/resources/img/animals/hare.png"
#define    APPLE_PATH         "app/resources/img/food/apple.png"
#define    CARROT_PATH        "app/resources/img/food/carrot.png"
/*
* Standart constructor for the Simulation class.
* @param    main_window_size        is the  size of the main simulation window
* @param    full_simulation_name    is the name of the simulation
*/
Simulation::Simulation(sf::Vector2u main_window_size, const string full_simulation_name) {
	this->mainWindowSize.x = main_window_size.x;
	this->mainWindowSize.y = main_window_size.y;
	this->mainWindow = new sf::RenderWindow(sf::VideoMode(main_window_size.x, main_window_size.y), full_simulation_name);
	this->backGround = new BackGround(BACKGROUND_PATH);

	//Generate the animal's tracks
	tracks = {
		 new Track(sf::Vector2f(0, 220),TRACK_PATH),
		 new Track(sf::Vector2f(0, 420), TRACK_PATH)
	};	
	//Generate the finish flags on the animal's tracks
	for (Track* track : tracks)
		track->setFinishFlag(new Flag(sf::Vector2f(track->getPosition().x + mainWindowSize.x-100,
			                                        track->getPosition().y - 50),
			                                        FLAG_PATH));
	//Generate animals
	animals = {
		new Turtle(sf::Vector2f(tracks[0]->getPosition().x - 10,
                               tracks[0]->getPosition().y - 10),
                                                  TURTLE_PATH),

		new Hare(sf::Vector2f(tracks[1]->getPosition().x - 10,
                             tracks[1]->getPosition().y - 20),
                                                   HARE_PATH)       
	};

	//Generate foodBasket
	foodBasket = {
                    new PackageOfFood(new Food(sf::Vector2f(0, 0),
					 "Apple",
					 APPLE_PATH),
					 tracks[0], 3),

                    new PackageOfFood(new Food(sf::Vector2f(0, 0),
					 "Carrot",
					 CARROT_PATH),
					 tracks[1], 3)
	};
}

/*
* Standart constructor for the Simulation class
*/
Simulation::~Simulation() {
	delete this->mainWindow;
	delete this->backGround;
	for (Track* track : tracks)
		delete track;
	for (Animal* animal : animals)
		delete animal;
	for (PackageOfFood* packageOfFood :  foodBasket)
		delete packageOfFood;
}
/*
* This function handles all events
*/
void Simulation::processEvents() {
	sf::Event event;
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time /= 800;
	while (this->mainWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			this->mainWindow->close();
	}
}
/*
*This function updates the game logic
*/
void Simulation::update() {
	for (Animal* animal : animals) {
		animal->getRandomMovement();
		animal->animate(time);
		animal->update(time);
	}
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
	for (Animal* animal : animals) {		
		animal->draw(mainWindow);
	}

	for (auto packageOfFood : foodBasket)
		packageOfFood->draw(mainWindow);

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




