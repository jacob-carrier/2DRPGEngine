#include "Player.h"

namespace RPGEngine{
	namespace Entities{
		Player::Player() : Entity(){
		}

		Player::Player(const std::string& entityName) : Entity(entityName){
		}

		void Player::Update(){

		}

		void Player::Render(sf::RenderWindow& window){

		}
	}
}