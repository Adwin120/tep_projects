#pragma once
#include <iostream>
class RefCounter
{
public:
	RefCounter();
	~RefCounter();
	int add();
	int dec();
	int get();
private:
	int count;
};

