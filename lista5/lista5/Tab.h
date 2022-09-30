#pragma once
#include <iostream>
#define DEF_TAB_SIZE 10
class Tab
{
public:
	Tab();
	Tab(const Tab& other);
	Tab(Tab&& other);
	Tab operator=(const Tab& other);
	~Tab();
	Tab operator=(Tab&& other);
	bool setSize(int newSize);
	int getSize();
private:
	void copy(const Tab& other);
	
	int* tab;
	int size;
};

