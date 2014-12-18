#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "BaseResource.h"
#include "TextureResource.h"

#include <map>
#include <iostream>

namespace RPGEngine{
	namespace Resources{
		class ResourceManager{
			public:
				ResourceManager();
				~ResourceManager();
				template <typename T>
				T* GetResource(const std::string&);
			private:
				std::map<std::string, BaseResource*> resources;
		};

		template <typename T>
		T* ResourceManager::GetResource(const std::string& filename){
			if(resources.find(filename) == resources.end()){
				std::cout << "Resource file not in cache: " << filename << std::endl;
				T* resource = new T();
				resource->LoadFromFile(filename);
				resources.insert(std::make_pair(filename, resource));
			}

			return dynamic_cast<T*>(resources[filename]);
		}
	}
}

#endif