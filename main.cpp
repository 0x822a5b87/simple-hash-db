//
// Created by 0x822a5b87 on 2022/6/25.
//

#include <iostream>
#include <sstream>
#include "core/core.cpp"
#include "storage/storage.cpp"

void writeData(Storage &storage)
{
	storage.set("hello0", "world0", 6);
	storage.set("hello1", "world1", 6);
	storage.set("hello2", "world2", 6);
	storage.set("hello3", "world3", 6);
	storage.set("hello4", "world4", 6);
}

const char *read(Storage &storage, const char *key)
{
	const char *data = storage.get(key);
	return data;
}


void test0()
{
//	std::stringstream ss;
//	Storage           storage(ss, ss);
	std::ifstream in("/Users/dhy/tmp/db/data");
	std::ofstream ou("/Users/dhy/tmp/db/data");
	Storage storage(in, ou);

	writeData(storage);
	assert(std::string(read(storage, "hello0")) == "world0");
	assert(std::string(read(storage, "hello1")) == "world1");
	assert(std::string(read(storage, "hello2")) == "world2");
	assert(std::string(read(storage, "hello3")) == "world3");
	assert(std::string(read(storage, "hello4")) == "world4");
	assert(std::string(read(storage, "hello4")) == "world4");
	storage.set("hello4", "new world4", 10);
	assert(std::string(read(storage, "hello4")) == "new world4");
	storage.del("hello0");
	storage.del("hello4");
	assert(storage.get("hello0") == nullptr);
	assert(storage.get("hello4") == nullptr);
	assert(storage.get("hello-1") == nullptr);
}

int main(int argc, char **argv)
{
	test0();

	return 0;
}