#include "Physics.h"
#include "raylib.h"
physObj::physObj()
{
	pos = { 0,0 };
	vel = { 0,0 };
	forces = { 0,0 };
	mass = 1.0f;
	drag = 1.0f;
}

void physObj::tickPhys(float delta)
{
	vel += forces * delta;
	forces = { 0,0 };

	//vel *= (1.0f - delta * drag);

	pos += vel * delta;
}

void physObj::draw() const
{
	DrawCircle(pos.x, pos.y, 15.0f, PINK);
}

void physObj::addForce(glm::vec2 force)
{
	forces += force * (1.0f / mass);
}
