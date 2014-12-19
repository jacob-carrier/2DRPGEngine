#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "Entity.h"
#include <map>
#include <string>

namespace RPGEngine{
	namespace Entities{
		class EntityManager{
			public:
				EntityManager();

				template <typename T>
				T* GetEntity(const std::string&);

				template <typename T>
				T* CreateEntity(const std::string&);

				void Render(sf::RenderWindow& window);
				void Update();
			private:
				std::map<std::string, Entity*> entities;
		};

		template <typename T>
		T* EntityManager::GetEntity(const std::string& entityName){
			return entities[entityName];
		}

		template <typename T>
		T* EntityManager::CreateEntity(const std::string& entityName){
			if(entities.find(entityName) == entities.end()){
				//Entity doesn't exist
				T* entity = new T(entityName);
				entities.insert(std::make_pair(entityName, entity));

				return entity;
			}else{			
				//If there is an entity with the same name, simply update the entityUID and attach to the name. Ie: npc, npc_1, npc_2, etc.
				T* entity = dynamic_cast<T*>(entities[entityName]);
				int lastID = entity->getEntityUID();
				T* new_entity = new T(entity->getEntityID() + "_" + std::to_string(++lastID));
				new_entity->setEntityUID(lastID);
				entities.insert(std::make_pair(new_entity->getEntityID(), new_entity));
				return new_entity;
			}

			return NULL;
		}
	}
}

#endif