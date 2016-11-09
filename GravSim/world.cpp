#include "world.h"

World::World(sf::RenderWindow& w) :
window(w),
world_view(window.getDefaultView()),
world_bounds(0.f, 0.f, world_view.getSize().x, world_view.getSize().y),
scene_graph()
{
	//window.setView(world_view);
	LoadTextures();
	BuildScene();
}

void World::Update(sf::Time dt)
{
	size_t num_entities = entities.size();
	for (int i = 0; i < num_entities; i++){
		for (int j = i + 1; j < num_entities; j++){
			ApplyGravity(entities[i], entities[j]);
		}
	}
	for (int i = 0; i < num_entities; i++){
		entities[i]->Update(dt);
	}
	//scene_graph.Update(dt);
}

void World::draw()
{
	//window.setView(world_view);
	size_t num_entities = entities.size();
	for (int i = 0; i < num_entities; i++){
		window.draw(*entities[i]);
	}
	//window.draw(scene_graph);
}

void World::LoadTextures()
{

}

#define VELOCITY  18.0
void World::BuildScene()
{
	Entity* ball = new Entity(sf::Vector2f(VELOCITY, 0.f), 20000.f, 10.f);
	ball->SetPosition(sf::Vector2f(180.f, 100.f));
	entities.push_back(ball);
	ball = new Entity(sf::Vector2f(-VELOCITY, 0.f), 20000.f, 10.f);
	ball->SetPosition(sf::Vector2f(220.f, 200.f));
	entities.push_back(ball);
	ball = new Entity(sf::Vector2f(-20.f, -40.f), 2.f, 2.f);
	ball->SetPosition(sf::Vector2f(340.f, 140.f));
	entities.push_back(ball);
	ball = new Entity(sf::Vector2f(20.f, 43.f), 2.f, 2.f);
	ball->SetPosition(sf::Vector2f(80.f, 166.f));
	entities.push_back(ball);
	//scene_graph.AttachChild(std::move(ball));
	
}