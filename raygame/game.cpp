#include "game.h"

#include "raylib.h"
#include<iostream>
game::game() 
{
	targetFixedStep = 1.0f / 30.0f;
	accumulatedFixedTime = 0.0f;
}
void game::init()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
}

void game::tick()
{
	accumulatedFixedTime += GetFrameTime();
	if (IsMouseButtonPressed(0))
	{
		physObjs.emplace_back();
		std::cout << "Added a physics object!" << std::endl;
		auto& babyPhys = physObjs[physObjs.size() - 1];
		auto mousePos = GetMousePosition();
		babyPhys.pos = { mousePos.x,mousePos.y };
		babyPhys.addForce({ 0,1000 });

	}
}

void game::tickPhys()
{
	accumulatedFixedTime -= targetFixedStep;

	for (auto& i : physObjs)
	{
		i.tickPhys(targetFixedStep);
	}
}

void game::draw() const
{
	BeginDrawing();

	ClearBackground(BLACK);

	for (const auto& i : physObjs)
	{
		i.draw();
	}

	EndDrawing();
}

void game::exit()
{
}

bool game::shouldClose() const
{
	return WindowShouldClose();
}

bool game::shouldPhysics() const
{
	return accumulatedFixedTime >= targetFixedStep;
}


