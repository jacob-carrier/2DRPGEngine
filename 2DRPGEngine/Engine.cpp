#include "stdafx.h"
#include "Engine.h"
#include <string>
#include <iostream>

namespace RPGEngine{
	Engine::Engine(int width, int height, const std::string& title){
		std::cout << "Engine launching" << std::endl;
		window.create(sf::VideoMode(width, height), title.c_str());

		static_entity = new Entities::Entity();
		resourceManager = new Resources::ResourceManager();

		Resources::TextureResource* res = resourceManager->GetResource<Resources::TextureResource>("town95.png");

		Components::SpriteComponent* sprite = new Components::SpriteComponent(static_entity, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 32, 32);
		sprite->setSpritesheet(res->Texture());

		static_entity->RegisterComponent("sprite", sprite);

		this->running = true;
	}

	Engine::~Engine(){
		
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
		static_entity->Render(window);
		window.display();
	}
}