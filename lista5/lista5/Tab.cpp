#include "Tab.h"

Tab::Tab()
{
	tab = new int[DEF_TAB_SIZE];
	size = DEF_TAB_SIZE;
}

Tab::Tab(const Tab& other)
{
	copy(other);
	std::cout << "Copy ";
}

Tab::Tab(Tab&& other)
{
    tab = other.tab;
    size = other.size;
    other.tab = NULL;
    std::cout << "MOVE ";
}

Tab Tab::operator=(const Tab& other)
{
    if (other.tab == tab)
    {
        return *this;
    }
	if (tab != NULL) delete[] tab;
	copy(other);
	std::cout << "op= ";
	return(*this);
}

Tab::~Tab()
{
	if (tab != NULL) delete[] tab;
	std::cout << "Destr ";
}

Tab Tab::operator=(Tab&& other)
{
    if (tab == other.tab)
    {
        return *this;
    }
    if (tab != NULL) 
    {
        delete[] tab;
    }
    tab = other.tab;
    size = other.size;

    other.tab = NULL;

    return *this;
}

bool Tab::setSize(int newSize)
{
    if (newSize <= 0) {
        return false;
    }

    int* newTab = new int[newSize];
    int smallerSize = (size < newSize) ? size : newSize;
    for (int i = 0; i < smallerSize; i++)
    {
        newTab[i] = tab[i];
    }
    size = newSize;
    delete[] tab;
    tab = newTab;
    return true;
}

int Tab::getSize()
{
    return size;
}

void Tab::copy(const Tab& other)
{
    tab = new int[other.size];
    size = other.size;
    for (int i = 0; i < other.size; i++)
    {
        tab[i] = other.tab[i];
    }
}
