#include <utility>

//
// Created by 0x822a5b87 on 2022/6/25.
//

#ifndef SIMPLE_HASH_DB_DATA_HPP
#define SIMPLE_HASH_DB_DATA_HPP

class Data
{
public:
	const size_t keyLen;
	const size_t valLen;
	std::string  key;
	const char   *val;

	Data(const size_t keyLen, const size_t valLen, std::string key, const char *val) :
			keyLen(keyLen),
			valLen(valLen),
			key(std::move(key)),
			val(val)
	{}
};


class FileStorageIndex
{
public:
	const size_t offset;

	explicit FileStorageIndex(const size_t &offset) : offset(offset)
	{}
};

#endif //SIMPLE_HASH_DB_DATA_HPP
