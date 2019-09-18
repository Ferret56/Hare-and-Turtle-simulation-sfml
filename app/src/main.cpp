#include "Simulation.h"
#define MAX_RENDER_WINDOW_WIDTH  1280
#define MAX_RENDER_WINDOW_HEIGHT 720

int main(){
	     srand(time(NULL));
         Simulation simulation(sf::Vector2u(MAX_RENDER_WINDOW_WIDTH,MAX_RENDER_WINDOW_HEIGHT),
		                                                        "Hare and Turtle simulation");
         simulation.run();
         return 0;
}