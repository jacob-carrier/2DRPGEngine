#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"
#include <SFML\Graphics.hpp>

namespace RPGEngine{
	namespace Entities{
		class Entity;
	}
	namespace Components{
		//class Entities::Entity;
		class Component{
			public:
				//friend class RPGEngine::Entities::Entity
				Component(Entities::Entity* e);
				virtual void Update();
				virtual void Render(sf::RenderWindow& window);
			private:
				Entities::Entity* entity;
		};
	}
}

#endif