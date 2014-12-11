#include "stdafx.h"
#include "Engine.h"
#include <string>
#include <iostream>

namespace RPGEngine{
	Engine::Engine(int width, int height, const std::string& title){
		std::cout << "Engine launching" << std::endl;
		window.create(sf::VideoMode(width, height), title.c_str());
		map = new RPGEngine::Map::TiledMap("Data/Maps/forest_path.tmx");
		this->running = true;
	}

	Engine::~Engine(){
		delete map;
	}

	void Engine::Run(){
		while(this->running){
			while(window.isOpen()){
				this->Update();
				this->Render();
			}
		}
	}

	sf::RenderWindow& Engine::Window(){
		return window;
	}

	void Engine::Update(){
	
		//this->elapsedTime = clock->restart();

		while(window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				this->running = false;
				window.close();
			}
		}
	}

	void Engine::Render(){
		window.clear();
		//Render Here
		map->Render(window);
		window.display();
	}
}