//
// Created by 0x822a5b87 on 2022/6/25.
//

#ifndef SIMPLE_HASH_DB_CORE_HPP
#define SIMPLE_HASH_DB_CORE_HPP


#include <string>
#include <iostream>
#include "Serializer.hpp"
#include "Deserializer.hpp"

template<class type>
class core
{
public:
	core();

	core(const Serializer<type> &serializer, const Deserializer<type> &deserializer);

	virtual ~core();

	/**
	 * get message with key `k`
	 * @param k key
	 * @return value
	 */
	std::string get(const std::string &k);

	/**
	 * set key `k` with value `v`
	 * @param k key
	 * @param v value
	 * @return set result
	 */
	bool set(const std::string &k, const type &v);

	/**
	 * delete key `k`
	 * @param k key
	 * @return delete result
	 */
	bool del(const std::string &k);

private:
	Serializer<type>   *serializer;
	Deserializer<type> *deserializer;
};

#endif //SIMPLE_HASH_DB_CORE_HPP
