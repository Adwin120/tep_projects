// lista1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


void vAllocTableAdd5(int iSize)
{
    const int iOffset = 5;

    if (iSize >= 0)
    {
        int* piTable;
        piTable = new int[iSize];
        for (int i = 0; i < iSize; i++)
        {
            piTable[i] = i + iOffset;
        }
        for (int i = 0; i < iSize; i++)
        {
            std::cout << piTable[i] << std::endl;
        }
        delete[] piTable;
    }
}

bool bAllocTable2Dim(int*** piTable, int iSizeX, int iSizeY)
{
    if (iSizeX <= 0 || iSizeY <= 0)
    {
        return false;
    }
    *piTable = new int* [iSizeY];
    for (int i = 0; i < iSizeY; i++)
    {
        (*piTable)[i] = new int[iSizeX];
    }
    return true;
}

bool bDeallocTable2Dim(int** piTable, int iSizeX, int iSizeY)
{
    if (iSizeX <= 0 || iSizeY <= 0) {
        return false;
    }
    for (int i = 0; i < iSizeY; i++)
    {
        delete[] piTable[i];
    }
    delete[] piTable;
    return true;
}

class CTable
{
public:
    CTable()
    {
        sTableName = sDefaultTableName;
        std::cout << "bezp: " << sTableName << std::endl;
        iTableSize = iDefaultTableSize;
        piTable = new int[iTableSize];
    }

    CTable(std::string sName, int iTableLen)
    {
        sTableName = sName;
        std::cout << "parametr: " << sTableName << std::endl;
        iTableSize = iTableLen;
        piTable = new int[iTableSize];
    }

    CTable(CTable& pcOther)
    {
        sTableName = pcOther.sTableName + "_copy";
        iTableSize = pcOther.iTableSize;
        piTable = new int[iTableSize];
        for (int i = 0; i < iTableSize; i++)
        {
            piTable[i] = pcOther.piTable[i];
        }
        std::cout << "kopiuj: " << sTableName << std::endl;
    }

    ~CTable()
    {
        std::cout << "usuwam: " << sTableName << std::endl;
        delete[] piTable;
    }

    void vSetName(std::string sName)
    {
        sTableName = sName;
    }

    bool bSetNewSize(int iTableLen)
    {
        if (iTableLen <= 0) {
            return false;
        }

        int* piNewTable = new int[iTableLen];
        int iSmallerLen = (iTableSize < iTableLen) ? iTableSize : iTableLen;
        for (int i = 0; i < iSmallerLen; i++)
        {
            piNewTable[i] = piTable[i];
        }
        iTableSize = iTableLen;
        delete[] piTable;
        piTable = piNewTable;
        return true;
    }

    CTable* pcClone()
    {
        CTable cClone(*this);
        return &cClone;
    }
    std::string sTableName;
    int* piTable;
    int iTableSize;
private:
    const std::string sDefaultTableName = "tablica";
    const int iDefaultTableSize = 10;
};

void vModTab(CTable* pcTab, int iNewSize)
{
    pcTab->bSetNewSize(iNewSize);
}
void vModTab(CTable cTab, int iNewSize)
{
    cTab.bSetNewSize(iNewSize);
}

int main()
{
    vAllocTableAdd5(10);

    std::cout << "--------\n";

    int** piTable;
    std::cout << bAllocTable2Dim(&piTable, 5, 3) << std::endl;
    bDeallocTable2Dim(piTable, 5, 3);

    std::cout << "--------\n";

    CTable cTab;
    vModTab(cTab, 12);
    std::cout << cTab.iTableSize << std::endl;
    vModTab(&cTab, 15);
    std::cout << cTab.iTableSize << std::endl;
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
