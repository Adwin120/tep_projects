// projektTEP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include "CGAOptimizer.h"
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "MySmartPointer.h"

int main()
{
    srand(time(NULL));

    double crossingChance = 0.3;
    double mutationChance = 0.05;
    int populationSize = 200;
    int iterationCount = 300;

    MySmartPointer<ProblemInterface> m3s(new CMax3SatProblem());
    bool success = m3s->load("max3sat/50/m3s_30_9.txt");
    /*std::cout << success;*/
    CGAOptimizer optimizer(m3s, crossingChance, mutationChance, populationSize);
    optimizer.initialize();

    for (int i = 0; i < iterationCount; i++)
    {
        if (i % 20 == 0)
        {
            std::cout << i << " " << optimizer.getBestResult()->fitness() << "\n";
        }
        optimizer.runIteration();
    }
    std::cout << "results fitness: " << optimizer.getBestResult()->fitness() << std::endl;
    std::vector<bool> result = myDyanamicCast<IndividualInterface, CGAIndividual>(optimizer.getBestResult())->getResult();
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
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
