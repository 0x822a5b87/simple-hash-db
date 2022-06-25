//
// Created by 0x822a5b87 on 2022/6/25.
//

#ifndef SIMPLE_HASH_DB_SERIALIZER_HPP
#define SIMPLE_HASH_DB_SERIALIZER_HPP


template<class type>
class Serializer
{
public:
	Serializer()
	{
		std::cout << "new serializer" << std::endl;
	}

	virtual ~Serializer()
	{
		std::cout << "del serializer" << std::endl;
	}

	virtual const char *serialize(type data) = 0;
};

#endif //SIMPLE_HASH_DB_SERIALIZER_HPP
