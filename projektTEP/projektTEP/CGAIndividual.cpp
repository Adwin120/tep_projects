#include "CGAIndividual.h"

CGAIndividual::CGAIndividual(int problem_size, MySmartPointer<ProblemInterface> problem_pointer)
{
	genotype = std::vector<bool>(problem_size, 0);
	problem = problem_pointer;
	size = problem_size;
	for (int i = 0; i < size; i++)
	{
		genotype[i]=(rand() % 2 == 0);
	}
	fit = problem->compute(genotype);
}

CGAIndividual::CGAIndividual(std::vector<bool>& given_genotype, MySmartPointer<ProblemInterface> problem_pointer)
{
	problem = problem_pointer;
	size = given_genotype.size();
	genotype = given_genotype;
	fit = problem->compute(genotype);
}

std::vector<bool> CGAIndividual::getResult()
{
	return genotype;
}

std::vector<MySmartPointer<IndividualInterface>> CGAIndividual::crossover(IndividualInterface& other, float chance)
{
	CGAIndividual& othercga = static_cast<CGAIndividual&>(other);
	std::vector<MySmartPointer<IndividualInterface>> resultVector(2);
	if (getRandomDouble() < chance)
	{
		/*MySmartPointer<CGAIndividual> child1(new CGAIndividual(size, problem));
		MySmartPointer<CGAIndividual> child2(new CGAIndividual(size, problem));*/
		std::vector<bool> child1genotype(size);
		std::vector<bool> child2genotype(size);
		for (int i = 0; i < size; i++)
		{
			if (rand() % 2 == 0)
			{
				child1genotype[i] = this->genotype[i];
				child2genotype[i] = othercga.genotype[i];
			}
			else
			{
				child1genotype[i] = othercga.genotype[i];
				child2genotype[i] = this->genotype[i];
			}
		}
		/*resultVector.push_back(myDyanamicCast<CGAIndividual, IndividualInterface>(child1));
		resultVector.push_back(myDyanamicCast<CGAIndividual, IndividualInterface>(child2));*/
		resultVector[0] = MySmartPointer<IndividualInterface>(new CGAIndividual(child1genotype, problem));
		resultVector[1] = MySmartPointer<IndividualInterface>(new CGAIndividual(child2genotype, problem));
	}
	else
	{
		resultVector[0] = MySmartPointer<IndividualInterface>(new CGAIndividual(*this));
		resultVector[1] = MySmartPointer<IndividualInterface>(new CGAIndividual(othercga));
	}
	return resultVector;
}

MySmartPointer<IndividualInterface> CGAIndividual::mutation(float chance)
{
	CGAIndividual* newChild = new CGAIndividual(*this);
	//std::cout << fit << " ";
	for (int i = 0; i < size; i++)
	{
		if (getRandomDouble() < chance)
		{
			newChild->genotype[i] = !genotype[i];
		}
	}
	newChild->updateFitness();
	//std::cout << newChild->fitness() << std::endl;
	return MySmartPointer<IndividualInterface>(newChild);
}

int CGAIndividual::fitness()
{
	return fit;
}

double CGAIndividual::getRandomDouble()
{
	return rand() / (RAND_MAX + 1.);
}

void CGAIndividual::updateFitness()
{
	fit = problem->compute(genotype);
}
