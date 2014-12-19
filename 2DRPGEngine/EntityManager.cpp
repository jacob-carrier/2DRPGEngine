#include "EntityManager.h"

namespace RPGEngine{
	namespace Entities{
		EntityManager::EntityManager(){

		}

		void EntityManager::Render(sf::RenderWindow& window){
			for(auto& entity : entities){
				entity.second->Render(window);
			}
		}

		void EntityManager::Update(){
			for(auto& entity : entities){
				entity.second->Update();
			}
		}
	}
}