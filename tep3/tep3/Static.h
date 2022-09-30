#pragma once
#include <vector>
#include <iostream>
using namespace std;

class NodeStatic
{
public:
	NodeStatic();
	~NodeStatic();

	void setValue(int newVal);
	int getValue();

	int getChildrenNumber();
	void addNewChild();
	NodeStatic* getChild(int childOffset);
	NodeStatic* getParent();

	void print();
	void printAllBelow();

	void printUp();

	void pushChildNode(NodeStatic& newChildNode);
	bool removeChildNode(NodeStatic* childNode);
	void fixParentPointers();
private:
	vector<NodeStatic> children;
	NodeStatic* parentNode;
	int val;
};

class TreeStatic
{
public:
	TreeStatic();
	~TreeStatic();

	NodeStatic* getRoot();
	void printTree();

	bool moveSubtree(NodeStatic* parentNode, NodeStatic* newChildNode);
private:
	NodeStatic root;
};

