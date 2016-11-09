#include "game.h"

Game::Game()
: window(sf::VideoMode(X_RES, Y_RES), TITLE),
world(window)
{
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time last_update = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 30.f);
	while (window.isOpen())
	{
		last_update += clock.restart();
		while (last_update > TimePerFrame)
		{
			last_update -= TimePerFrame;
			ProcessEvents();
			Update(TimePerFrame);
		}
		Render();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) window.close();
	}
}

void Game::Update(sf::Time delta_time)
{
	world.Update(delta_time);

}

void Game::Render()
{
	window.clear();
	world.draw();
	window.display();
}