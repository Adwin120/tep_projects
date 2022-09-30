#pragma once
#include "IndividualInterface.h"
#include "ProblemInterface.h"
#include <vector>
class CGAIndividual :
	public IndividualInterface
{
public:
	CGAIndividual(int size, MySmartPointer<ProblemInterface> problem_pointer);
	CGAIndividual(std::vector<bool>& given_genotype, MySmartPointer<ProblemInterface> problem_pointer);
	std::vector<bool> getResult();

	// Inherited via IndividualInterface
	virtual std::vector<MySmartPointer<IndividualInterface>> crossover(IndividualInterface& other, float chance) override;
	virtual MySmartPointer<IndividualInterface> mutation(float chance) override;
	virtual int fitness() override;
private:
	std::vector<bool> genotype;
	int size;
	MySmartPointer<ProblemInterface> problem;
	int fit;
	double getRandomDouble();
	void updateFitness();
};

