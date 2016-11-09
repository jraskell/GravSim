#include "scene.h"
#include <cassert>

SceneNode::SceneNode() :
children(),
parent(nullptr)
{
}

void	SceneNode::Update(sf::Time dt)
{
	UpdateCurrent(dt);
	UpdateChildren(dt);
}


void SceneNode::AttachChild(Ptr c)
{
	c->parent = this;
	children.push_back(std::move(c));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(children.begin(), children.end(),
		[&](Ptr& p) -> bool { return p.get() == &node; });

	assert(found != children.end());

	Ptr result = std::move(*found);
	result->parent = nullptr;
	children.erase(found);
	return result;
}

sf::Transform SceneNode::GetWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->parent){
		transform = node->getTransform() * transform;
	}
	return transform;
}
sf::Vector2f	SceneNode::GetWorldPosition() const
{
	return GetWorldTransform() * sf::Vector2f();
}

void SceneNode::UpdateCurrent(sf::Time dt)
{

}
void SceneNode::UpdateChildren(sf::Time dt)
{
	for (auto& c : children){
		c->Update(dt);
	}
}


void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);
	for(auto& c : children)
	{
		c->draw(target, states);
	}
}
void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
	
}