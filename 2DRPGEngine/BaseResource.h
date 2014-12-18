#ifndef BASE_RESOURCE_H
#define BASE_RESOURCE_H

#include <string>

namespace RPGEngine{
	namespace Resources{
		class BaseResource{
			public:
				BaseResource();
				virtual void LoadFromFile(const std::string&);
			private:
		};
	}
}

#endif