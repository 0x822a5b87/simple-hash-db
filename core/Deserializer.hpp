//
// Created by 0x822a5b87 on 2022/6/25.
//

#ifndef SIMPLE_HASH_DB_DESERIALIZER_HPP
#define SIMPLE_HASH_DB_DESERIALIZER_HPP


template<class type>
class Deserializer
{
public:
	Deserializer()
	{
		std::cout << "new deserializer" << std::endl;
	}

	virtual ~Deserializer()
	{
		std::cout << "del deserializer" << std::endl;
	}
	virtual type deserialize(const char *) = 0;
};

#endif //SIMPLE_HASH_DB_DESERIALIZER_HPP
