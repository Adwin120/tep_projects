#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer(MySmartPointer<ProblemInterface> problem_pointer, float crossing_Chance, float mutation_Chance, int population_Size)
{
	crossChance = crossing_Chance;
	mutateChance = mutation_Chance;
	populationSize = population_Size;
	problem = problem_pointer;
}

void CGAOptimizer::initialize()
{
	population = std::vector<MySmartPointer<IndividualInterface>>(populationSize);
	currentBest = problem->getRandomSolution(problem);
	population[0] = currentBest;
	for (int i = 1; i < populationSize; i++)
	{
		MySmartPointer<IndividualInterface> random = problem->getRandomSolution(problem);
		if (random->fitness() > currentBest->fitness())
		{
			currentBest = random;
		}
		population[i] = random;
	}
}

void CGAOptimizer::runIteration()
{
	std::vector<MySmartPointer<IndividualInterface>> newPopulation(populationSize);
	for (int i = 0; i < populationSize; i += 2)
	{
		MySmartPointer<IndividualInterface> parent1 = chooseParent(population), parent2 = chooseParent(population);
		std::vector<MySmartPointer<IndividualInterface>> children = parent1->crossover(*parent2, crossChance);
		children[0]->mutation(mutateChance);
		children[1]->mutation(mutateChance);
		if (children[0]->fitness() > currentBest->fitness())
		{
			currentBest = children[0];
		}
		if (children[1]->fitness() > currentBest->fitness())
		{
			currentBest = children[1];
		}
		newPopulation[i] = children[0];
		newPopulation[i+1] = children[1];
	}

	population = newPopulation;
}

MySmartPointer<IndividualInterface> CGAOptimizer::chooseParent(std::vector<MySmartPointer<IndividualInterface>> population)
{
	MySmartPointer<IndividualInterface> parentCandidate1 = population[rand() % population.size()];
	MySmartPointer<IndividualInterface> parentCandidate2 = population[rand() % population.size()];

	if (parentCandidate1->fitness() > parentCandidate2->fitness())
	{
		return parentCandidate1;
	}
	else 
	{
		return parentCandidate2;
	}
}

MySmartPointer<IndividualInterface> CGAOptimizer::getBestResult()
{
	return currentBest;
}
