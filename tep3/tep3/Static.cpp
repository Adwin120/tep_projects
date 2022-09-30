#include "Static.h"

NodeStatic::NodeStatic()
{
	val = 0;
	parentNode = NULL;
}

NodeStatic::~NodeStatic()
{
	//cout << " usuwam static:" << val << endl;
}

void NodeStatic::setValue(int newVal)
{
	val = newVal;
}

int NodeStatic::getValue()
{
	return val;
}

int NodeStatic::getChildrenNumber()
{
	return children.size();
}

void NodeStatic::addNewChild()
{
	NodeStatic newChild;
	newChild.parentNode = this;
	children.push_back(newChild);
}

NodeStatic* NodeStatic::getChild(int childOffset)
{
	if (childOffset >= 0 && childOffset < children.size())
	{
		return &children[childOffset];
	}
	return NULL;
}

NodeStatic* NodeStatic::getParent()
{
	return parentNode;
}

void NodeStatic::print()
{
	cout << " " << val;
}

void NodeStatic::printAllBelow()
{
	print();
	for (int i = 0; i < children.size(); i++)
	{
		children[i].printAllBelow();
	}
}

void NodeStatic::printUp()
{
	print();
	if(parentNode != NULL)
	{
		parentNode->printUp();
	}
}

void NodeStatic::pushChildNode(NodeStatic& newChildNode)
{
	newChildNode.parentNode = this;
	children.push_back(newChildNode);
	//newChildNode.fixParentPointers();
	// 
	//vector<NodeStatic> childsChildren = children[children.size() - 1].children;
	//for (int i = 0; i < childsChildren.size(); i++)
	//{
	//	childsChildren[i].parentNode = &children[children.size() - 1];
	//}
}

bool NodeStatic::removeChildNode(NodeStatic* childNode)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (&(children[i]) == childNode)
		{
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}

void NodeStatic::fixParentPointers()
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i].parentNode = this;
		children[i].fixParentPointers();
	}
}

TreeStatic::TreeStatic()
{
	root = NodeStatic();
}

TreeStatic::~TreeStatic()
{
}

NodeStatic* TreeStatic::getRoot()
{
	return &root;
}

void TreeStatic::printTree()
{
	root.printAllBelow();
	cout << endl;
}

bool TreeStatic::moveSubtree(NodeStatic* parentNode, NodeStatic* newChildNode)
{
	NodeStatic* newChildNodeParent = newChildNode->getParent();
	parentNode->pushChildNode(*newChildNode);
	newChildNodeParent->removeChildNode(newChildNode);
	root.fixParentPointers();
	return true;
}
