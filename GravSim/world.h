#pragma once

#include <SFML\Graphics.hpp>
#include "scene.h"
#include "entity.h"

class World : private sf::NonCopyable
{
public:
	explicit	World(sf::RenderWindow& window);
	void		Update(sf::Time dt);
	void		draw();

private:
	sf::RenderWindow&	window;
	sf::View			world_view;
	SceneNode			scene_graph;
	std::vector<Entity*>	entities;
	sf::FloatRect		world_bounds;

	void		LoadTextures();
	void		BuildScene();

};