#include "Entity.h"

namespace RPGEngine{
	namespace Entities{
		Entity::Entity(){
			
		}

		Entity::Entity(const std::string& entityName){
			e_id = entityName;
			u_id = 0;
		}

		void Entity::RegisterComponent(const std::string& componentName, Components::Component* component){
			components.insert(std::pair<std::string, Components::Component*>(componentName, component));
		}

		void Entity::Update(){
			for(auto& component : components){
				component.second->Update();
			}
		}

		void Entity::Render(sf::RenderWindow& window){
			for(auto& component : components){
				component.second->Render(window);
			}
		}
	}
}