#ifndef TEXTURE_RESOURCE_H
#define TEXTURE_RESOURCE_H

#include "BaseResource.h"
#include <SFML\Graphics.hpp>

namespace RPGEngine{
	namespace Resources{
		class TextureResource : public BaseResource{
			public:
				TextureResource();
				~TextureResource();
				void LoadFromFile(const std::string&) override;
				sf::Texture* Texture();
			private:
				sf::Texture* texture;
		};
	}
}

#endif