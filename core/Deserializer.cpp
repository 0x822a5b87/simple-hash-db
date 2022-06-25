//
// Created by 0x822a5b87 on 2022/6/25.
//

#include <string>
#include "Deserializer.hpp"

class DefaultDeserializer: public Deserializer<std::string>
{
public:
	DefaultDeserializer()
	{
		std::cout << "new default deserializer" << std::endl;
	}

	~DefaultDeserializer() override
	{
		std::cout << "del default deserializer" << std::endl;
	}

public:
	std::string deserialize(const char * data) override
	{
		return std::string(data);
	}
};