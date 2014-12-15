#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"

namespace RPGEngine{
	namespace Components{
		class SpriteComponent : Component{
			public:
				SpriteComponent(Entities::Entity* e, sf::Vector2f, sf::Vector2f, int, int);
				~SpriteComponent();
				void Update() override;
				void Render(sf::RenderWindow&) override;
				void setSpritesheet(sf::Texture*);
			private:
				sf::Sprite* sprite;
				sf::Texture* spritesheet;
		};
	}
}

#endif