#pragma once

#include "glm//vec2.hpp"
#include "shapes.h"
class physObj
{
public:
	glm::vec2 pos;
	glm::vec2 vel;

	glm::vec2 forces;

	physObj();

	float mass;
	float drag;

	shape collider;

	void tickPhys(float delta);
	void draw() const;

	// Add a constant force with respect to mass
	void addForce(glm::vec2 force);
	// Add an instant force with respect to mass
	void addImpulse(glm::vec2 impulse);
	// Acelerates the object without respect to mass
	void addAccel(glm::vec2 accel);
	// Adds an instant force without respect to mass
	void addVelocityChange(glm::vec2 delta);
};