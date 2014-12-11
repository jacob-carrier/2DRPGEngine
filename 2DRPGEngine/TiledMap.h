#ifndef TILEDMAP_H
#define TILEDMAP_H

#include "tinyxml2.h"
#include "Tile.h"
#include <string>
#include <vector>

using namespace tinyxml2;

namespace RPGEngine{
	namespace Map{
		struct TilesetImage{
			std::string imageSource;
			int width;
			int height;
		};

		struct Tileset{
			int firstGID;
			std::string name;
			int tileWidth;
			int tileHeight;

			TilesetImage image;
		};		

		struct Layer{
			std::string name;
			int width;
			int height;
			std::vector<Tile> tiles;
		};

		class TiledMap{
			public:
				TiledMap(const std::string& sourceFile);
				void Render(sf::RenderWindow& window);
				//Will update animated tiles
				void Update();
			private:
				XMLDocument* tiledDoc;
				int width, height, tileWidth, tileHeight;
				std::map<int, std::vector<sf::IntRect>> tilesetRects;
				std::vector<Tileset> tilesets;
				std::vector<Layer> layers;
				sf::Texture* tex;
		};
	}
}

#endif