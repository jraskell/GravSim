#pragma once

#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable,
	private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

	SceneNode();

	void	Update(sf::Time dt);
	void	AttachChild(Ptr c);
	Ptr		detachChild(const SceneNode& node);

	sf::Transform	GetWorldTransform() const;
	sf::Vector2f	GetWorldPosition() const;

	SceneNode*		GetParent(){ return parent; }
private:
	std::vector<Ptr>	children;
	SceneNode*			parent;

	virtual void	UpdateCurrent(sf::Time dt);
	void			UpdateChildren(sf::Time dt);

	virtual void	draw(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual void	drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
};

