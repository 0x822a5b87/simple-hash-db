//
// Created by 0x822a5b87 on 2022/6/25.
//

#include "core.hpp"
#include "Serializer.cpp"
#include "Deserializer.cpp"

template<class T>
std::string core<T>::get(const std::string &k)
{
	const char * bytes = k.data();
	std::string data = deserializer->deserialize(bytes);
	std::cout << "get before serialize [" << k << "], after serialize [" << data << "]" << std::endl;
	return std::string();
}

template<class type>
bool core<type>::set(const std::string &k, const type &v)
{
	auto data = serializer->serialize(v);
	std::cout << "set before deserialize [" << v << "], after deserialize [" << data << "]" << std::endl;
	return false;
}

template<class type>
bool core<type>::del(const std::string &k)
{
	std::cout << "del " << k << std::endl;
	return false;
}

template<class type>
core<type>::core()
{
	this->serializer   = new DefaultSerializer();
	this->deserializer = new DefaultDeserializer();
}

template<class type>
core<type>::core(const Serializer<type> &serializer,
				 const Deserializer<type> &deserializer)
		:serializer(serializer),
		 deserializer(deserializer)
{}

template<class type>
core<type>::~core()
{
	delete serializer;
	delete deserializer;
}
