// lista5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MySmartPointer.h"
#include "Tab.h"

struct Base
{
	virtual ~Base() {
		std::cout << "deleting base\n";
	}
	void name() 
	{
		std::cout << "Base\n";
	}
};
struct Derived : Base
{
	void name() 
	{
		std::cout << "Derived\n";
	}
};


int main()
{
	//MySmartPointer<Tab> pointer(new Tab());
	//pointer->setSize(5);
	//std::cout << (*pointer).getSize() << std::endl;
	//Tab tab1, tab2;
	//tab1.setSize(2);
	//tab2.setSize(4);

	//std::cout << tab1.getSize() << std::endl;
	//std::cout << tab2.getSize() << std::endl;
	//tab1 = std::move(tab2);
	//std::cout << tab1.getSize() << std::endl;
	//std::cout << tab2.getSize() << std::endl;
	MySmartPointer<Derived> pointerDerived(new Derived());
	pointerDerived->name();
	MySmartPointer<Base> castedPointerBase = myDyanamicCast<Derived, Base>(pointerDerived);
	castedPointerBase->name();

	MySmartPointer<Base> pointerBase(new Base());
	pointerBase->name();
	MySmartPointer<Derived> castedPointerDerived = myDyanamicCast<Base, Derived>(pointerBase);
	castedPointerDerived->name();
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
