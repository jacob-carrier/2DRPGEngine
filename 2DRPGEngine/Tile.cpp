#include "stdafx.h"
#include "Tile.h"

namespace RPGEngine{
	namespace Map{
		Tile::Tile(int x, int y, int width, int height)
		{
			tile_sprite.setPosition(x, y);
			tile_sprite.setTextureRect(sf::IntRect(0, 0, width, height));
		}

		Tile::~Tile(){

		}

		void Tile::SetTilesheet(const sf::Texture& tilesheet){
			tile_sprite.setTexture(tilesheet);
		}

		void Tile::Render(sf::RenderWindow& window){
			window.draw(tile_sprite);
		}

		void Tile::Update(sf::Time& time){
			//Possibility of using animated Tiles
		}
	}
}