#include "entity.h"

void ApplyGravity(Entity* e1, Entity* e2)
{
	float m1 = e1->GetMass(), m2 = e2->GetMass();
	sf::Vector2f p1 = e1->GetPosition(), p2 = e2->GetPosition();
	double r = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));

	double f = grav_const * (m1 * m2) / (r * r);
	//Compute the direction vectors for each entity
	sf::Vector2f n1((p2.x - p1.x) / r, (p2.y - p1.y) / r);
	sf::Vector2f n2((p1.x - p2.x) / r, (p1.y - p2.y) / r);

	//Compute the acceleration for each entity
	double a1 = f / m1;
	double a2 = f / m2;

	double ax1, ay1, ax2, ay2;

	ax1 = n1.x * a1;
	ay1 = n1.y * a1;

	ax2 = n2.x * a2;
	ay2 = n2.y * a2;
	//sf::Vector2f va1(n1.x * a1, n1.y * a1);
	//sf::Vector2f va2(n2.x * a2, n2.y * a2);

	e1->ApplyAcceleration(ax1, ay1);
	e2->ApplyAcceleration(ax2, ay2);
}

Entity::Entity()
{
	vx = 80.0;
	vy = 80.0;
	velocity = sf::Vector2f(80.f, 80.f);
	acceleration = sf::Vector2<double>(0.0, 0.0);
	shape.setRadius(10.f);
	setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);
}

Entity::Entity(sf::Vector2f v, float m, float r)
{
	vx = v.x;
	vy = v.y;
	velocity = v;
	radius = r;
	mass = m;
	shape.setRadius(radius);
	setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(r, r);
}

void Entity::ApplyAcceleration(double ax, double ay)
{
	acceleration += sf::Vector2<double>(ax, ay);
}

void Entity::UpdateCurrent(sf::Time dt)
{

	velocity.x += acceleration.x * dt.asSeconds();
	velocity.y += acceleration.y * dt.asSeconds();

	acceleration = sf::Vector2<double>(0.0, 0.0);
	move(velocity * dt.asSeconds());
	//setPosition(pos.x + vx*dt.asSeconds(), pos.y + vy*dt.asSeconds());
	shape.setPosition(getPosition());
}

void Entity::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
	target.draw(line, 2, sf::Lines);
}