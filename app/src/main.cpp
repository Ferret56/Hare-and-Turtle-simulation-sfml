#include "Simulation.h"

int main(){
	Simulation simulation(sf::Vector2u(1280,720),"Hare and Turtle simulation");
	simulation.run();
    return 0;
}