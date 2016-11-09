#pragma once

#include <SFML\Graphics.hpp>
#include "scene.h"

const double grav_const = 6.674f;

class Entity : public SceneNode
{
public:
	Entity();
	Entity(sf::Vector2f v, float m, float r);

	void			SetVelocity(sf::Vector2f v);
	sf::Vector2f	GetVelocity() { return velocity; }

	void			ApplyAcceleration(double ax, double ay, sf::Time dt);

	void			SetMass(float m){ mass = m; }
	float			GetMass(){ return mass; }

	void			SetRadius(float r){ radius = r; shape.setRadius(radius); }
	float			GetRadius(){ return radius; }

	void			SetPosition(sf::Vector2f p){ setPosition(p); }
	sf::Vector2f	GetPosition(){ return getPosition(); }

	void			SetColor(sf::Color c){ shape.setFillColor(c); }

private:
	sf::Vector2f		velocity;
	double				vx, vy;
	float				mass;
	float				radius;
	virtual void		UpdateCurrent(sf::Time dt);
	sf::CircleShape		shape;
	sf::Vertex			line[2];
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};