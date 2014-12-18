#ifndef ENGINE_H
#define ENGINE_H
#include <SFML\Graphics.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\System\Time.hpp>

#include "Entity.h"
#include "SpriteComponent.h"
#include "ResourceManager.h"

namespace RPGEngine
{
	public class Engine{
		public:
			Engine(int width, int height, const std::string& title);
			~Engine();
			void Run();

			//Get Window Might not be necessary
			sf::RenderWindow& Window();
		private:
			void Update();
			void Render();

			Entities::Entity* static_entity;
			Resources::ResourceManager* resourceManager;

			sf::RenderWindow window;
			sf::Time elapsedTime;
			sf::Clock clock;
			sf::Event event;
			sf::Texture* tex;
			bool running;
	};
}
#endif