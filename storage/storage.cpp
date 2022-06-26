//
// Created by 0x822a5b87 on 2022/6/25.
//

#include "iostream"
#include "storage.hpp"
#include "data.hpp"

const char *Storage::get(const std::string &k)
{
	FileStorageIndex *index = dbIndex[k];
	if (index == nullptr)
	{
		return nullptr;
	}
	reader.seekg(index->offset);
	Data data = readData();
	if (data.deleted == DELETED)
	{
		return nullptr;
	}
	return data.val;
}

FileStorageIndex Storage::set(const std::string &k, const char *data, size_t dataLen)
{
	std::ostream::pos_type begin = writer.tellp();
	writeInt(k.length());
	writeInt(dataLen);
	writeInt(NOT_DELETED);
	writer << k;
	writer << data;
	writer.flush();
	dbIndex[k] = new FileStorageIndex{begin};
	return FileStorageIndex{begin};
}

FileStorageIndex Storage::del(const std::string &k)
{
	std::ostream::pos_type begin = writer.tellp();
	writeInt(k.length());
	writeInt(0);
	writeInt(DELETED);
	writer << k;
	writer.flush();
	dbIndex[k] = new FileStorageIndex{begin};
	return FileStorageIndex{begin};
}

Storage::~Storage()
{
	clearIndex();
}

void Storage::initIndex()
{
	size_t offset = 0;
	while (nextData())
	{
		Data data = readData();
		dbIndex[data.key] = new FileStorageIndex(offset);
		offset = reader.tellg();
	}
	reader.clear();
}

void Storage::clearIndex()
{
	for (const auto &kv : dbIndex)
	{
		delete kv.second;
	}
}

Data Storage::readData()
{
	size_t keyLen = readInt();
	size_t valLen = readInt();
	size_t deleted = readInt();
	char   *k     = new char[keyLen+1]();
	reader.read(k, keyLen);
	char *v = new char[valLen+1]();
	reader.read(v, valLen);
	return Data{keyLen, valLen, deleted, k, v};
}

void Storage::writeInt(int len)
{
	char num_char[INT_SIZE];
	std::sprintf(num_char, "%d", len);
	writer.write(num_char, INT_SIZE);
}

int Storage::readInt()
{
	char numChar[INT_SIZE];
	numChar[3] = 1;
	reader.read(numChar, INT_SIZE);
	return std::stoi(numChar);
}

bool Storage::nextData()
{
	char ch = reader.get();
	reader.seekg(-1, std::ios::cur);
	if (ch == -1)
	{
		reader.clear();
	}
	return ch != -1;
}

Storage::Storage(std::istream &r, std::ostream &w) : reader(r), writer(w)
{
	initIndex();
}

