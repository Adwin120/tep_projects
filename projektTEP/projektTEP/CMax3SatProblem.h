#pragma once
#include "ProblemInterface.h"
#include "CGAIndividual.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctype.h>

class CMax3SatProblem :
	public ProblemInterface
{
public:
	CMax3SatProblem();
	// Inherited via ProblemInterface
	virtual bool load(std::string resourcePath) override;
	virtual int compute(std::vector<bool>& solution) override;
	virtual MySmartPointer<IndividualInterface> getRandomSolution(MySmartPointer<ProblemInterface> usingProblemPointer) override;
private:
	std::vector<std::vector<int>> clauses;
	void printClauses();
	int variableAmount;
};

