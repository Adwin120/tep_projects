#pragma once
#include <string>
#include <vector>
#include "IndividualInterface.h"
class ProblemInterface
{
public:
	virtual ~ProblemInterface();
	virtual bool load(std::string resourcePath) = 0;
	virtual int compute(std::vector<bool>& solution) = 0;
	virtual MySmartPointer<IndividualInterface> getRandomSolution(MySmartPointer<ProblemInterface> usingProblemPointer) = 0;
};

