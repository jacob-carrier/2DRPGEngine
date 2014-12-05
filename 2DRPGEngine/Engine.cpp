#include "stdafx.h"
#include "Engine.h"
#include <string>
#include <iostream>

namespace RPGEngine{
	Engine::Engine(int width, int height, const std::string& title){
		window.create(sf::VideoMode(width, height), title.c_str());
	
		this->running = true;
		tex = new sf::Texture();
		if(!tex->loadFromFile("Data/Inq XP MT- Medieval Town.png", sf::IntRect(0,0,256,64))){
			std::cout << "Couldn't Load Texture" << std::endl;
		}
		single_tile = new Map::Tile(0, 0, 32, 32);
		single_tile->SetTilesheet(*tex);
	}

	Engine::~Engine(){
		delete tex;
		delete single_tile;
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
		single_tile->Render(window);
		window.display();
	}
}