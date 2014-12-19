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
				Entity(const std::string&);
				virtual void Update();
				virtual void Render(sf::RenderWindow& window);
				void RegisterComponent(const std::string&, Components::Component*);
				Components::Component* GetComponent(const std::string& componentName) {return components[componentName];};
				const std::string& getEntityID(){return e_id;};
				int getEntityUID(){return u_id;};
				void setEntityUID(int id){u_id = id;};
			private:
				std::map<std::string, Components::Component*> components;
				std::string e_id;
				int u_id;
				//Entities::Component* component;				
		};
	}
}

#endif