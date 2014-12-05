#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "Engine.h"
using namespace RPGEngine;

int main()
{
	Engine* engine = new Engine(800, 600, "2D RPG Engine - Window");
	engine->Run();

	delete engine;

	return 0;
}