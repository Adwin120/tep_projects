#pragma once
#include <vector>
#include "MySmartPointer.h"
class IndividualInterface
{
public:
	virtual ~IndividualInterface();
	virtual std::vector<MySmartPointer<IndividualInterface>> crossover(IndividualInterface& other, float chance) = 0;
	virtual MySmartPointer<IndividualInterface> mutation(float chance) = 0;
	virtual int fitness() = 0;
};

