#ifndef TILE_H
#define TILE_H
#include <SFML\Graphics.hpp>

namespace RPGEngine
{
	namespace Map
	{
		class Tile{
			public:
				Tile(int x, int y, int width, int height);
				~Tile();
				void Render(sf::RenderWindow&);
				void Update(sf::Time& time);
				//void Load()
				void SetTilesheet(const sf::Texture& tilesheet);
			private:
				int x, y, tileWidth, tileHeight;
				sf::Sprite tile_sprite;
		};
	}
}
#endif