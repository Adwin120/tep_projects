// przeciazenieOperatorow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Table.h"
void vModTab(Table* pcTab, int iNewSize)
{
    pcTab->setNewSize(iNewSize);
}
void vModTab(Table cTab, int iNewSize)
{
    cTab.setNewSize(iNewSize);
}
int main()
{
    Table cTab;
    vModTab(cTab, 12);
    std::cout << cTab.getTableSize() << std::endl;
    vModTab(&cTab, 15);
    std::cout << cTab.getTableSize() << std::endl;

    std::cout << "------zad1-2-------\n";

    Table tab1_0, tab1_1;
    tab1_0.setNewSize(6);
    tab1_1.setNewSize(4);
    tab1_0 = tab1_1;

    std::cout << "------zad3-4-------\n";

    Table tab3_0, tab3_1;
    tab3_0.setNewSize(6);
    tab3_1.setNewSize(4);
    //tab0 = [1,2,3,4,5,6]
    for (int i = 0; i < 6; i++)
    {
        tab3_0.setValueAt(i, i + 1);
    }
    //tab1 = [51,52,53,54]
    for (int i = 0; i < 4; i++)
    {
        tab3_1.setValueAt(i, 51 + i);
    }

    tab3_0 = tab3_1;
    tab3_1.setValueAt(2, 123);
    tab3_0.print();
    tab3_1.print();
    (tab3_0 + tab3_1).print();

    Table testTable;
    testTable.setNewSize(6);

    testTable.setValueAt(0,1);
    testTable.setValueAt(1,2);
    testTable.setValueAt(2,3);
    testTable.setValueAt(3,4);
    testTable.setValueAt(4,5);
    testTable.setValueAt(5,6);

    (testTable << 2).print();
    (testTable >> 2).print();

    for (int i = 0; i < 15; i++)
    {
        (testTable >> i).print();
    }

    std::cout << "---------------------\n";

    for (int i = 0; i < 15; i++)
    {
        (testTable << i).print();
    }
    (testTable << -1).print();
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
