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

void physObj::addImpulse(glm::vec2 impulse)
{
	vel += impulse * (1.0f / mass);
}

void physObj::addAccel(glm::vec2 accel)
{
	forces += accel;
}

void physObj::addVelocityChange(glm::vec2 delta)
{
	vel += delta;

}
