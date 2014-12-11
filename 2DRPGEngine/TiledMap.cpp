#include "TiledMap.h"
#include <iostream>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

namespace RPGEngine{
	namespace Map{
		TiledMap::TiledMap(const std::string& sourceFile){
			tiledDoc = new XMLDocument();
			XMLError error = tiledDoc->LoadFile(sourceFile.c_str());

			if(error != XML_SUCCESS){
				std::cout << "Couldn't load map:" << sourceFile << std::endl;
				std::cout << error << std::endl;
			}

			XMLElement* mapRoot = tiledDoc->FirstChildElement("map");

			//Store general map information
			mapRoot->QueryIntAttribute("width", &width);
			mapRoot->QueryIntAttribute("height", &height);
			mapRoot->QueryIntAttribute("tilewidth", &tileWidth);
			mapRoot->QueryIntAttribute("tileheight", &tileHeight);

			XMLElement* tilesetElement = mapRoot->FirstChildElement("tileset");

			tex = new sf::Texture();
			tex->loadFromFile("Data/mountain_landscape_23.png");
			
			while(tilesetElement){
				//Read the current tileset info
				Tileset tileset;

				tilesetElement->QueryIntAttribute("firstgid", &tileset.firstGID);
				tileset.name = tilesetElement->Attribute("name");
				tilesetElement->QueryIntAttribute("tilewidth", &tileset.tileWidth);
				tilesetElement->QueryIntAttribute("tileheight", &tileset.tileHeight);

				XMLElement* imageElement = tilesetElement->FirstChildElement("image");
				
				//Grab the tileset image, and attach it to the tileset
				TilesetImage image;
				image.imageSource = imageElement->Attribute("source");
				imageElement->QueryIntAttribute("width", &image.width);
				imageElement->QueryIntAttribute("height", &image.height);

				tileset.image = image;

				std::vector<sf::IntRect> tileSubRects;


				//Divide the tileset into SFML Rects, to use sub rect the tiles on render
				int column = tileset.image.width / tileWidth;
				int row = tileset.image.height / tileHeight;

				for(int y = 0; y < row; y++){
					for(int x = 0; x < column; x++){
						sf::IntRect rect;

						rect.top = y * tileHeight;
						rect.left = x * tileWidth;
						rect.width = tileWidth;
						rect.height = tileHeight;

						tileSubRects.push_back(rect);
					}
				}

				//Store and map the tileset firstGID to the tile sub rects
				tilesetRects.insert(std::make_pair(tileset.firstGID, tileSubRects));

				//Store the actual tileset
				tilesets.push_back(tileset);

				tilesetElement = tilesetElement->NextSiblingElement("tileset");
			}

			//Loop over the layers and store the tiles
			XMLElement* layerElement = mapRoot->FirstChildElement("layer");
			
			/*
			if(!tex->loadFromFile("Data/town95.png")){
				std::cout << "Couldn't Load Texture" << std::endl;
			}*/

			

			while(layerElement){
				Layer layer;
				layer.name = layerElement->Attribute("name");

				XMLElement* layerDataElement = layerElement->FirstChildElement("data");

				if(layerDataElement == NULL){
					std::cout << "No tile data in this tileset" << std::endl;
				}

				XMLElement* tileElement = layerDataElement->FirstChildElement("tile");

				int x = 0;
				int y = 0;
				int i = 0;

				while(tileElement){
					int tileGID = atoi(tileElement->Attribute("gid"));
					if(tilesets[i].firstGID > tileGID && tileGID > 0){
						i++;
					}
					int subRectId = tileGID - tilesets[i].firstGID;
					if(subRectId >= 0){
						Tile tile(x*tileWidth, y*tileHeight, tileWidth, tileHeight);
							
						//Need to add a resource loader
						//tile.SetTilesheet(tileset.image.imageSource);
						//For now, hardcode tilesheet name

						
						tile.SetTilesheet(tex);
						tile.SetSubRect(tilesetRects[tilesets[i].firstGID][subRectId]);
							
						layer.tiles.push_back(tile);
						std::cout << "Pushing a tile on layer: " << layer.name << std::endl;
					}

					tileElement = tileElement->NextSiblingElement("tile");

					x++;
					if (x >= width)//if x has "hit" the end (right) of the map, reset it to the start (left)
					{
						x = 0;
						y++;
						if (y >= height)
						{
							y = 0;
						}
					}
				}
				std::cout << "Pushing layer: " << layer.name << std::endl;
				layerElement = layerElement->NextSiblingElement("layer");
				layers.push_back(layer);
				
			}		
		}

		void TiledMap::Render(sf::RenderWindow& window){
			for(int layer = 0; layer < layers.size(); layer++){
				for(int tile = 0; tile < layers[layer].tiles.size(); tile++){
					layers[layer].tiles[tile].Render(window);
				}
			}
		}
	}
}