#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML\Graphics.hpp>

namespace RPGEngine{
	namespace Entities{
		class Player : Entity{
			public:
				Player();
				Player(const std::string&);
				void Update() override;
				void Render(sf::RenderWindow& window) override;
			private:
				
		};
	}
}

#endif