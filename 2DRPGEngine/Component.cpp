#include "Component.h"

namespace RPGEngine{
	namespace Components{
		
		Component::Component(Entities::Entity* e){
			this->entity = e;
		}
		
		void Component::Update(){

		}

		void Component::Render(sf::RenderWindow& window){

		}
	}
}