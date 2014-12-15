#include "SpriteComponent.h"

namespace RPGEngine{
	namespace Components{
		SpriteComponent::SpriteComponent(Entities::Entity* e, sf::Vector2f position, sf::Vector2f texPos, int width, int height) : Component(e){
			sprite = new sf::Sprite();
			sprite->setPosition(position);
			sprite->setTextureRect(sf::IntRect(texPos.x, texPos.y, width, height));
		}

		void SpriteComponent::setSpritesheet(sf::Texture* tex){
			sprite->setTexture(*tex);
		}

		void SpriteComponent::Update(){

		}

		void SpriteComponent::Render(sf::RenderWindow& window){
			window.draw(*sprite);
		}
	}
}