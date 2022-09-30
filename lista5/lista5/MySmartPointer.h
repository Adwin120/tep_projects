#pragma once
#include "RefCounter.h"

template<typename T>
class MySmartPointer
{
public:
	MySmartPointer(T* newPointer);
	MySmartPointer(T* newPointer, RefCounter* usedCounter);
	~MySmartPointer();
	MySmartPointer(const MySmartPointer& other);
	MySmartPointer<T>& operator=(const MySmartPointer<T>& other);

	T* getPointer() const;
	RefCounter* getCounter() const;

	T& operator*();
	T* operator->();
private:
	T* pointer;
	RefCounter* counter;
};

template<typename T>
inline MySmartPointer<T>::MySmartPointer(T* newPointer)
{
	pointer = newPointer;
	counter = new RefCounter();
	counter->add();
}

template<typename T>
inline MySmartPointer<T>::~MySmartPointer()
{
	if (counter->dec() == 0)
	{
		delete pointer;
		delete counter;
	}
}

template<typename T>
inline MySmartPointer<T>::MySmartPointer(const MySmartPointer& other)
{
	pointer = other.pointer;
	counter = other.counter;
	counter->add();
}

template<typename T>
inline MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer<T>& other)
{
	if (other.pointer == this->pointer)
	{
		return this;
	}

	if (counter->dec() == 0)
	{
		delete pointer;
		delete counter;
	}

	pointer = other.pointer;
	counter = other.counter;
	counter->add();

	return this;
}

template<typename T>
inline T* MySmartPointer<T>::getPointer() const
{
	return pointer;
}

template<typename T>
inline RefCounter* MySmartPointer<T>::getCounter() const
{
	return counter;
}

template<typename T>
inline T& MySmartPointer<T>::operator*()
{
	return *pointer;
}

template<typename T>
inline T* MySmartPointer<T>::operator->()
{
	return pointer;
}

template<typename T>
inline MySmartPointer<T>::MySmartPointer(T* newPointer, RefCounter* usedCounter)
{
	pointer = newPointer;
	counter = usedCounter;
	counter->add();
}

template<class Src, class Dst>
MySmartPointer<Dst> myDyanamicCast(const MySmartPointer<Src>& srcPtr)
{
	Src* innerSrcPtr = srcPtr.getPointer();
	Dst* innerDstPtr = dynamic_cast<Dst*>(innerSrcPtr);
	if (innerDstPtr == nullptr)
	{
		RefCounter* counter = new RefCounter();
		counter->add();
		MySmartPointer<Dst> brokenPointer(innerDstPtr, counter);
		return brokenPointer;
	}
	MySmartPointer<Dst> dstPtr(innerDstPtr, srcPtr.getCounter());
	return dstPtr;
}