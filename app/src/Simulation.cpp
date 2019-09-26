#include "Simulation.h"
#include"PackageOfFood.h"
#pragma once
#define    BACKGROUND_IMAGE_PATH    "app/resources/img/background/background.png"
#define    TRACK_IMAGE_PATH         "app/resources/img/track/track.png"
#define    FLAG_IMAGE_PATH          "app/resources/img/finish/flag.png"
#define    TURTLE_IMAGE_PATH        "app/resources/img/animals/turtle.png"
#define    HARE_IMAGE_PATH          "app/resources/img/animals/hare.png"
#define    APPLE_IMAGE_PATH         "app/resources/img/food/apple.png"
#define    CARROT_IMAGE_PATH        "app/resources/img/food/carrot.png"

/*
* Standart constructor for the Simulation class.
* @param    main_window_size        is the  size of the main simulation window
* @param    full_simulation_name    is the name of the simulation
*/
Simulation::Simulation(sf::Vector2u main_window_size, const string full_simulation_name) {
	this->mainWindowSize.x = main_window_size.x;
	this->mainWindowSize.y = main_window_size.y;
	this->mainWindow = new sf::RenderWindow(sf::VideoMode(main_window_size.x, main_window_size.y), full_simulation_name);
	this->backGround = new BackGround(BACKGROUND_IMAGE_PATH);
	this->isTheSimulationStart = false;
	this->isTheRaceWin = false;

	//Generate the animal's tracks
	tracks = {
		 new Track(sf::Vector2f(0, 220),TRACK_IMAGE_PATH),
		 new Track(sf::Vector2f(0, 420), TRACK_IMAGE_PATH)
	};	
	//Generate the finish flags on the animal's tracks
	for (Track* track : tracks)
		track->setFinishFlag(new Flag(sf::Vector2f(track->getPosition().x + mainWindowSize.x-100,
			                                        track->getPosition().y - 50),
			                                        FLAG_IMAGE_PATH));
	//Generate animals
	animals = {
		new Turtle(sf::Vector2f(tracks[0]->getPosition().x - 10,
                               tracks[0]->getPosition().y - 10),
                                             TURTLE_IMAGE_PATH),

		new Hare(sf::Vector2f(tracks[1]->getPosition().x - 10,
                             tracks[1]->getPosition().y - 20),
                                              HARE_IMAGE_PATH)       
	};

	//Generate foodBasket
	foodBasket = {
                    new PackageOfFood(new Food(sf::Vector2f(0, 0),
					 "Apple",
					 APPLE_IMAGE_PATH),
					 tracks[0], 3),

                    new PackageOfFood(new Food(sf::Vector2f(0, 0),
					 "Carrot",
					 CARROT_IMAGE_PATH),
					 tracks[1], 3)
	};
	
	//Generate main text
	titleMessage = new Message("Hare and Turtle simulation", "app/resources/fonts/TSSSF.otf", 60);
	titleMessage->setPosition(mainWindow->getPosition().x + 60, mainWindow->getPosition().y + 130);

	//Generate description text
	descriptionMessage = new Message("Please press 'SPACE' to start the race", "app/resources/fonts/TSSSF.otf", 30);
	descriptionMessage->setPosition(mainWindow->getPosition().x + 125, mainWindow->getPosition().y + 350);
}

/*
* Standart destructor for the Simulation class
*/
Simulation::~Simulation() {
	delete this->mainWindow;
	delete this->backGround;
	delete this->titleMessage;
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
* This function updates the game logic
*/
void Simulation::update() {
	for (Animal* animal : animals) {
		if (animal->getSprite()->getPosition().x >= tracks[0]->getFinishFlag()->getSprite()->getPosition().x) {
			animal->setWinStatus(true);
			this->isTheRaceWin = true;
		}

		if (animal->isEatFood(&this->foodBasket)) {
			animal->activateBonus(true);
		}
		if (animal->getBonusStatus()) {
			animal->increaseCurrentBonusTime(time);
			if (animal->getCurrentBonusTime() >= animal->getTotalBonusTime())
				animal->activateBonus(false);
		}

		if(animal->getBonusStatus() == false)
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
		this->titleMessage->draw(mainWindow);
		this->descriptionMessage->draw(mainWindow);
		this->mainWindow->display();
	}

/*
* This function starts the simulation
*/
void Simulation::run() {	
	while (this->mainWindow->isOpen()) {
		processEvents();
		//start updating if the simulation has started
		if(isTheSimulationStart)
		        update();
		render();
	}
}




