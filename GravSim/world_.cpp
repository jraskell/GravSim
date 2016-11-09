#include "world.h"
#include "entity.h"

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
	scene_graph.Update(dt);
}

void World::draw()
{
	//window.setView(world_view);
	window.draw(scene_graph);
}

void World::LoadTextures()
{

}

void World::BuildScene()
{
	std::unique_ptr<Entity> ball(new Entity(sf::Vector2f(23.9278f, 0.f), 5.f, 10.f));
	ball->SetPosition(sf::Vector2f(200.f, 130.f));
	std::unique_ptr<Entity> ball2(new Entity(sf::Vector2f(0.f, 0.f), 6000.f, 30.f));
	ball2->SetPosition(sf::Vector2f(200.f, 200.f));
	ball->AttachChild(std::move(ball2));
	scene_graph.AttachChild(std::move(ball));
	
}