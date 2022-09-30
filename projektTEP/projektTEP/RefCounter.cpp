#include "RefCounter.h"

RefCounter::RefCounter()
{
	count = 0;
}

RefCounter::~RefCounter()
{

}

int RefCounter::add()
{
	return ++count;
}

int RefCounter::dec()
{
	return --count;
}

int RefCounter::get()
{
	return count;
}
