#include "CMax3SatProblem.h"

CMax3SatProblem::CMax3SatProblem()
{
    clauses = std::vector<std::vector<int>>();
    variableAmount = 0;
}

void CMax3SatProblem::printClauses()
{
    std::cout << "clauses:\n";
    for (int i = 0; i < clauses.size(); i++)
    {
        for (int j = 0; j < clauses[i].size(); j++)
        {
            std::cout << clauses[i][j] << " | ";
        }
        std::cout << "\n";
    }
}

bool CMax3SatProblem::load(std::string resourcePath)
{
    std::string clauseLine;
    std::ifstream problemFile(resourcePath);
    if (problemFile.fail())
    {
        return false;
    }
    while (getline(problemFile, clauseLine))
    {
        std::vector<int> currentClause;
        bool handlingNumber = false;
        bool numberNegative = false;
        std::string numberBuffer = "";
        for (int i = 0; i < clauseLine.size(); i++)
        {
            if (clauseLine[i] == ' ' && handlingNumber)
            {
                int number = (stoi(numberBuffer) + 1) * ((numberNegative) ? -1 : 1);
                currentClause.push_back(number);
                if (number > variableAmount)
                {
                    variableAmount = number;
                }

                handlingNumber = false;
                numberNegative = false;
                numberBuffer = "";
            }
            else if (clauseLine[i] == '-')
            {
                numberNegative = true;
            }
            else if (isdigit(clauseLine[i]))
            {
                handlingNumber = true;
                numberBuffer += clauseLine[i];
            }
        }
        clauses.push_back(currentClause);
    }
    problemFile.close();
    //printClauses();
    return true;
}

int CMax3SatProblem::compute(std::vector<bool>& solution)
{
    int fitness = 0;
    for (int i = 0; i < clauses.size(); i++)
    {
        std::vector<int> clause = clauses[i];
        for (int j = 0; j < clause.size(); j++)
        {
            int variableCode = clause[j];
            int variableName = abs(variableCode) - 1;
            if ((variableCode > 0) == (solution[variableName]))
            {
                fitness++;
                break;
            }
        }
    }
    return fitness;
}

MySmartPointer<IndividualInterface> CMax3SatProblem::getRandomSolution(MySmartPointer<ProblemInterface> usingProblemPointer)
{
    return MySmartPointer<IndividualInterface>(new CGAIndividual(variableAmount, usingProblemPointer));
}
