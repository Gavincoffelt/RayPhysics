#pragma once
#include<vector>

#include "Physics.h"

class game 
{
	float accumulatedFixedTime;
	std::vector<physObj> physObjs;
public:
	game();
	void init();
	void tick();
	void tickPhys();
	void draw() const;
	void exit();

	bool shouldClose() const;
	bool shouldPhysics() const;

	float targetFixedStep;
};