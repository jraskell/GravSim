#include <SFML\Graphics.hpp>
#define X_RES	640
#define Y_RES	480
#define TITLE	"GravSim"

#include "world.h"

class Game
{
public:
			Game();
	void	Run();

private:
	void	ProcessEvents();
	void	Update(sf::Time delta_time);
	void	Render();

	sf::RenderWindow	window;

	World				world;

};