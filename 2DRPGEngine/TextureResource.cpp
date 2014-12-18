#include "TextureResource.h"

namespace RPGEngine{
	namespace Resources{
		TextureResource::TextureResource() : BaseResource(){
			texture = new sf::Texture();
		}

		void TextureResource::LoadFromFile(const std::string& filename){
			texture->loadFromFile("Data/"+filename);
		}

		sf::Texture* TextureResource::Texture(){
			return texture;
		}
	}
}