//
// Created by 0x822a5b87 on 2022/6/25.
//

#ifndef SIMPLE_HASH_DB_STORAGE_HPP
#define SIMPLE_HASH_DB_STORAGE_HPP


#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "data.hpp"

const size_t INT_SIZE    = 8;
const size_t DELETED     = 0;
const size_t NOT_DELETED = 1;

class Storage
{
public:
	explicit Storage(std::istream &r, std::ostream &w);

	virtual ~Storage();

	/**
	 * get message with key `k`
	 * @param k key
	 * @return value
	 */
	const char *get(const std::string &k);

	/**
	 * set key `k` with value `v`
	 * @param k key
	 * @param v value
	 * @return set result
	 */
	FileStorageIndex set(const std::string &k, const char *data, size_t dataLen);

	/**
	 * delete key `k`
	 * @param k key
	 * @return delete result
	 */
	FileStorageIndex del(const std::string &k);

private:
	std::ostream                              &writer;
	std::istream                              &reader;
	std::map<std::string, FileStorageIndex *> dbIndex;

	bool nextData();

	Data readData();

	void initIndex();

	void clearIndex();

	void writeInt(int len);

	int readInt();
};

#endif //SIMPLE_HASH_DB_STORAGE_HPP
