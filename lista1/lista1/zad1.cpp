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

int main()
{
    vAllocTableAdd5(10);
    std::cout << "--------\n";
}