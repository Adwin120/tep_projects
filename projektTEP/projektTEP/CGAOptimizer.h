#pragma once
#include "OptimizerInterface.h"
#include "MySmartPointer.h"
#include "IndividualInterface.h"
#include "ProblemInterface.h"
class CGAOptimizer :
    public OptimizerInterface
{
public:
    CGAOptimizer(MySmartPointer<ProblemInterface> problem_pointer, float crossing_Chance, float mutation_Chance, int population_Size);
    // Inherited via OptimizerInterface
    virtual void initialize() override;
    virtual void runIteration() override;
    virtual MySmartPointer<IndividualInterface> getBestResult() override;
private:
    float crossChance;
    float mutateChance;
    int populationSize;
    MySmartPointer<IndividualInterface> currentBest;
    std::vector<MySmartPointer<IndividualInterface>> population;
    MySmartPointer<IndividualInterface> chooseParent(std::vector<MySmartPointer<IndividualInterface>> population);
    MySmartPointer<ProblemInterface> problem;
};

