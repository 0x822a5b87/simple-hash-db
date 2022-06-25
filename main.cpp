//
// Created by 0x822a5b87 on 2022/6/25.
//

#include <iostream>
#include "core/core.cpp"

int main(int argc, char **argv)
{
	core<std::string> c;
	c.get("hello");
	c.set("hello", "world");
	c.del("hello");
}