#pragma once
#include "MySmartPointer.h"
#include "IndividualInterface.h"
#include <iostream>

class OptimizerInterface
{
public:
	virtual ~OptimizerInterface();
	virtual void initialize() = 0;
	virtual void runIteration() = 0;
	virtual MySmartPointer<IndividualInterface> getBestResult() = 0;
};

