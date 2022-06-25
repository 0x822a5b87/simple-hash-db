//
// Created by 0x822a5b87 on 2022/6/25.
//

#include "iostream"
#include "storage.hpp"
#include "data.hpp"

const char *Storage::get(const std::string &k)
{
	FileStorageIndex *index = dbIndex[k];
	if (index != nullptr)
	{
		reader.seekg(index->offset);
		Data data = readData();
		return data.val;
	}
	else
	{
		return nullptr;
	}
}

FileStorageIndex Storage::set(const std::string &k, const char *data, size_t dataLen)
{
	std::ostream::pos_type begin = writer.tellp();
	writeInt(k.length());
	writeInt(dataLen);
	writer << k;
	writer << data;
	writer.flush();
	dbIndex[k] = new FileStorageIndex{begin};
	return FileStorageIndex{begin};
}

FileStorageIndex Storage::del(const std::string &k)
{
	return FileStorageIndex{0};
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
	char   *k     = new char[keyLen];
	reader.read(k, keyLen);
	char *v = new char[valLen];
	reader.read(v, valLen);
	return Data{keyLen, valLen, k, v};
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
	reader.read(numChar, INT_SIZE);
	return std::stoi(numChar);
}

bool Storage::nextData()
{
	char ch  = reader.get();
	reader.seekg(-1, std::ios::cur);
	if (ch == -1)
	{
		reader.clear();
	}
	return ch != -1;
}

Storage::Storage(std::istream& r, std::ostream& w): reader(r), writer(w)
{
	initIndex();
}

