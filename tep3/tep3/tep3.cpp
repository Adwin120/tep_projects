// tep3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Static.h"
#include "Dynamic.h"

void treeStaticTest()
{
    NodeStatic root;

    root.addNewChild();
    root.addNewChild();

    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);

    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();

    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);

    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();

    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);

    root.printAllBelow();
    cout << endl;
    root.getChild(0)->getChild(1)->printUp();
    cout << endl;
}

void treeDynamicTest()
{
    NodeDynamic<int> root;

    root.addNewChild();
    root.addNewChild();

    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);

    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();

    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);

    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();

    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);

    root.printAllBelow();
    cout << endl;
    root.getChild(0)->getChild(1)->printUp();
    cout << endl;
}

void treeStaticMoveTest()
{
    TreeStatic destTree;
    NodeStatic* destRoot = destTree.getRoot();

    destRoot->addNewChild();
    destRoot->addNewChild();
    destRoot->addNewChild();

    destRoot->getChild(0)->setValue(1);
    destRoot->getChild(1)->setValue(2);
    destRoot->getChild(2)->setValue(3);

    destRoot->getChild(2)->addNewChild();

    destRoot->getChild(2)->getChild(0)->setValue(4);

    TreeStatic srcTree;
    NodeStatic* srcRoot = srcTree.getRoot();

    srcRoot->setValue(50);

    srcRoot->addNewChild();
    srcRoot->addNewChild();

    srcRoot->getChild(0)->setValue(54);
    srcRoot->getChild(1)->setValue(55);

    srcRoot->getChild(0)->addNewChild();
    srcRoot->getChild(0)->addNewChild();

    srcRoot->getChild(0)->getChild(0)->setValue(56);
    srcRoot->getChild(0)->getChild(1)->setValue(57);

    srcRoot->getChild(0)->getChild(0)->addNewChild();

    srcRoot->getChild(0)->getChild(0)->getChild(0)->setValue(58);

    srcTree.printTree();
    destTree.printTree();
    srcRoot->getChild(0)->getChild(0)->getChild(0)->printUp();
    cout << endl << "move subtree" << endl;
    destTree.moveSubtree(destRoot->getChild(2), srcRoot->getChild(0));

    srcTree.printTree();
    destTree.printTree();
    destRoot->getChild(2)->getChild(1)->getChild(0)->getChild(0)->printUp();
    cout << endl << srcRoot->getChildrenNumber();
}

void treeDynamicMoveTest()
{
    TreeDynamic<int> destTree;
    NodeDynamic<int>* destRoot = destTree.getRoot();

    destRoot->addNewChild();
    destRoot->addNewChild();
    destRoot->addNewChild();

    destRoot->getChild(0)->setValue(1);
    destRoot->getChild(1)->setValue(2);
    destRoot->getChild(2)->setValue(3);

    destRoot->getChild(2)->addNewChild();

    destRoot->getChild(2)->getChild(0)->setValue(4);

    TreeDynamic<int> srcTree;
    NodeDynamic<int>* srcRoot = srcTree.getRoot();

    srcRoot->setValue(50);

    srcRoot->addNewChild();
    srcRoot->addNewChild();

    srcRoot->getChild(0)->setValue(54);
    srcRoot->getChild(1)->setValue(55);

    srcRoot->getChild(0)->addNewChild();
    srcRoot->getChild(0)->addNewChild();

    srcRoot->getChild(0)->getChild(0)->setValue(56);
    srcRoot->getChild(0)->getChild(1)->setValue(57);

    srcRoot->getChild(0)->getChild(0)->addNewChild();

    srcRoot->getChild(0)->getChild(0)->getChild(0)->setValue(58);

    srcTree.printTree();
    destTree.printTree();
    srcRoot->getChild(0)->getChild(0)->getChild(0)->printUp();
    cout << endl << "move subtree" << endl;
    destTree.moveSubtree(destRoot->getChild(2), srcRoot->getChild(0));

    srcTree.printTree();
    destTree.printTree();
    destRoot->getChild(2)->getChild(1)->getChild(0)->getChild(0)->printUp();
    cout << endl << srcRoot->getChildrenNumber();
}
template <typename T>
TreeDynamic<T> mergeTrees(TreeDynamic<T>& first, TreeDynamic<T>& second)
{
    TreeDynamic<T> resultTree;
    NodeDynamic<T>* resultRoot = resultTree.getRoot();
    resultRoot->setValue(324562);

    resultRoot->addNewChild();
    resultRoot->addNewChild();
    resultRoot->getChild(0)->setValue(first.getRoot()->getValue());
    resultRoot->getChild(1)->setValue(second.getRoot()->getValue());
    while (first.getRoot()->getChildrenNumber() > 0)
    {
        resultTree.moveSubtree(resultRoot->getChild(0), first.getRoot()->getChild(0));
    }
    while (second.getRoot()->getChildrenNumber() > 0)
    {
        resultTree.moveSubtree(resultRoot->getChild(1), second.getRoot()->getChild(0));
    }


    first.getRoot()->setValue(NULL);
    second.getRoot()->setValue(NULL);
    return resultTree;
}

void testMergeTrees()
{
    TreeDynamic<int> first, second;
    first.getRoot()->addNewChild();
    first.getRoot()->addNewChild();
    first.getRoot()->getChild(0)->setValue(1);
    first.getRoot()->getChild(1)->setValue(23);
    first.getRoot()->getChild(0)->addNewChild();
    first.getRoot()->getChild(0)->addNewChild();
    first.getRoot()->getChild(0)->getChild(0)->setValue(65);
    first.getRoot()->getChild(0)->getChild(1)->setValue(19);
    first.getRoot()->getChild(1)->addNewChild();
    first.getRoot()->getChild(1)->getChild(0)->setValue(127);

    second.getRoot()->setValue(2);
    second.getRoot()->addNewChild();
    second.getRoot()->addNewChild();
    second.getRoot()->getChild(0)->setValue(378);
    second.getRoot()->getChild(1)->setValue(68);
    second.getRoot()->getChild(0)->addNewChild();
    second.getRoot()->getChild(0)->addNewChild();
    second.getRoot()->getChild(0)->getChild(0)->setValue(66);
    second.getRoot()->getChild(0)->getChild(1)->setValue(7);

    first.printTree();
    second.printTree();
    TreeDynamic<int> resultTree = mergeTrees(first, second);
    resultTree.printTree();
    first.printTree();
    second.printTree();
}

void testCharTree()
{
    TreeDynamic<char> charTree;
    charTree.getRoot()->addNewChild();
    charTree.getRoot()->addNewChild();
    charTree.getRoot()->getChild(0)->setValue('a');
    charTree.getRoot()->getChild(1)->setValue('b');
    charTree.getRoot()->setValue('+');
    charTree.printTree();
}

int main()
{
    //treeStaticTest();
    //treeDynamicTest();
    //cout << endl << "static" << endl;
    //treeStaticMoveTest();
    //cout << endl << "dynamic" << endl;
    //treeDynamicMoveTest();
    testMergeTrees();
    testCharTree();
}