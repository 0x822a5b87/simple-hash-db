//
// Created by 0x822a5b87 on 2022/6/25.
//

#include "Serializer.hpp"

class DefaultSerializer : public Serializer<std::string>
{
public:
	DefaultSerializer()
	{
		std::cout << "new default serializer" << std::endl;
	}

	~DefaultSerializer() override
	{
		std::cout << "del default serializer" << std::endl;
	}
	const char *serialize(const std::string data) override
	{
		char *bytes = new char[data.length()];
		strcpy(bytes, data.c_str());
		return bytes;
	}
};