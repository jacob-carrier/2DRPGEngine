#include "stdafx.h"
#include "Engine.h"
#include <string>
#include <iostream>

namespace RPGEngine{
	Engine::Engine(int width, int height, const std::string& title){
		std::cout << "Engine launching" << std::endl;
		window.create(sf::VideoMode(width, height), title.c_str());

		entityManager = new Entities::EntityManager();

		static_entity = entityManager->CreateEntity<Entities::Entity>("static_entity");
		static_entity2 = entityManager->CreateEntity<Entities::Entity>("static_entity");
		resourceManager = new Resources::ResourceManager();

		Resources::TextureResource* res = resourceManager->GetResource<Resources::TextureResource>("town95.png");

		Components::SpriteComponent* sprite = new Components::SpriteComponent(static_entity, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 32, 32);
		Components::SpriteComponent* sprite2 = new Components::SpriteComponent(static_entity2, sf::Vector2f(32, 32), sf::Vector2f(0, 0), 32, 32);
		sprite->setSpritesheet(res->Texture());
		sprite2->setSpritesheet(res->Texture());

		static_entity->RegisterComponent("sprite", sprite);
		static_entity2->RegisterComponent("sprite", sprite2);

		std::cout << static_entity->getEntityID() << std::endl;
		std::cout << static_entity2->getEntityID() << std::endl;

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

		entityManager->Update();
	}

	void Engine::Render(){
		window.clear();
		//Render Here
		/*
		static_entity->Render(window);
		static_entity2->Render(window);
		*/
		entityManager->Render(window);
		window.display();
	}
}