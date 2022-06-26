//
// Created by 0x822a5b87 on 2022/6/25.
//

#include <iostream>
#include <json/value.h>
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


bool assertEqual(Storage& storage)
{
	std::string s("this is a long sentence and we used it to test!!!");
	storage.set("hello0", s.c_str(), s.length());
	const char *hello0 = storage.get("hello0");
	assert(std::string(hello0) == s);
	return true;
}

void testFileStorage()
{
	std::stringstream ss;
	Storage           storage(ss, ss);

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
	assertEqual(storage);
}

void testJson()
{
	Json::Value json;
	json["name"] = "Wiki";
	json["age"]  = 18;

	assert(json["name"] == "Wiki");
	assert(json["age"] == 18);
}

int main(int argc, char **argv)
{
	testFileStorage();
	testJson();

	return 0;
}