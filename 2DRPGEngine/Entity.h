#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <SFML\Graphics.hpp>
#include <map>
#include <string>


namespace RPGEngine{
	namespace Components{
		class Component;
	}

	namespace Entities{
		class Entity{
			public:
				Entity();
				virtual void Update();
				virtual void Render(sf::RenderWindow& window);
				void RegisterComponent(const std::string&, Components::Component*);
				Components::Component* GetComponent(const std::string& componentName) {return components[componentName];};
			private:
				std::map<std::string, Components::Component*> components;
				//Entities::Component* component;				
		};
	}
}

#endif