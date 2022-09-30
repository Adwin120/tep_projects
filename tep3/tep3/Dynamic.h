#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<typename T> class NodeDynamic
{
public:
	NodeDynamic();
	~NodeDynamic();
	NodeDynamic(const NodeDynamic& other);
	NodeDynamic& operator=(const NodeDynamic& other);


	void setValue(const T& newValue);
	T getValue();

	int getChildrenNumber();
	void addNewChild();
	NodeDynamic* getChild(int childOffset);
	NodeDynamic* getParent();

	void print();
	void printAllBelow();

	void printUp();

	void pushChildNode(NodeDynamic* newChildNode);
	bool removeChildNode(NodeDynamic* childNode);
private:
	vector<NodeDynamic*> children;
	NodeDynamic* parentNode;
	T val;
};

template <typename T>
class TreeDynamic
{
public:
	TreeDynamic();
	~TreeDynamic();
	TreeDynamic(const TreeDynamic<T>& other);
	TreeDynamic<T>& operator=(const TreeDynamic<T>& other);

	NodeDynamic<T>* getRoot();
	void printTree();
	bool moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode);
private:
	NodeDynamic<T>* root;
};

template <typename T>
TreeDynamic<T>::TreeDynamic()
{
    root = new NodeDynamic<T>();
}

template <typename T>
TreeDynamic<T>::~TreeDynamic()
{
    delete root;
}
template <typename T>
TreeDynamic<T>::TreeDynamic(const TreeDynamic<T>& other)
{
    root = new NodeDynamic<T>(*other.root);
}
template <typename T>
TreeDynamic<T>& TreeDynamic<T>::operator=(const TreeDynamic<T>& other)
{
    root = new NodeDynamic<T>(*other.root);
    return *this;
}
template <typename T>
NodeDynamic<T>* TreeDynamic<T>::getRoot()
{
    return root;
}
template <typename T>
void TreeDynamic<T>::printTree()
{
    root->printAllBelow();
    cout << endl;
}
template <typename T>
bool TreeDynamic<T>::moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode)
{
    NodeDynamic<T>* newChildNodeParent = newChildNode->getParent();
    parentNode->pushChildNode(newChildNode);
    newChildNodeParent->removeChildNode(newChildNode);
    return true;
}
template <typename T>
NodeDynamic<T>::NodeDynamic()
{
    val = 0;
    parentNode = NULL;
}
template <typename T>
NodeDynamic<T>::~NodeDynamic()
{
    //cout << " usuwam dynamic:" << val << endl;
    for (int i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
}
template <typename T>
NodeDynamic<T>::NodeDynamic(const NodeDynamic<T>& other)
{
    val = other.val;
    parentNode = other.parentNode;
    for (int i = 0; i < other.children.size(); i++)
    {
        children.push_back(new NodeDynamic<T>(*other.children[i]));
    }
}
template <typename T>
NodeDynamic<T>& NodeDynamic<T>::operator=(const NodeDynamic<T>& other)
{
    val = other.val;
    parentNode = other.parentNode;
    for (int i = 0; i < other.children.size(); i++)
    {
        children.push_back(new NodeDynamic<T>(*other.children[i]));
    }
    return *this;
}
template <typename T>
void NodeDynamic<T>::setValue(T newValue)
{
    val = newValue;
}
template <typename T>
T NodeDynamic<T>::getValue()
{
    return val;
}
template <typename T>
int NodeDynamic<T>::getChildrenNumber()
{
    return children.size();
}
template <typename T>
void NodeDynamic<T>::addNewChild()
{
    NodeDynamic<T>* newNode = new NodeDynamic<T>();
    newNode->parentNode = this;
    children.push_back(newNode);
}
template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getChild(int childOffset)
{
    if (childOffset >= 0 && childOffset < children.size())
    {
        return children[childOffset];
    }
    return NULL;
}
template <typename T>
NodeDynamic<T>* NodeDynamic<T>::getParent()
{
    return parentNode;
}
template <typename T>
void NodeDynamic<T>::print()
{
    cout << " " << val;
}
template <typename T>
void NodeDynamic<T>::printAllBelow()
{
    print();
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->printAllBelow();
    }
}
template <typename T>
void NodeDynamic<T>::printUp()
{
    print();
    if (parentNode != NULL)
    {
        parentNode->printUp();
    }
}
template <typename T>
void NodeDynamic<T>::pushChildNode(NodeDynamic<T>* newChildNode)
{
    newChildNode->parentNode = this;
    children.push_back(newChildNode);
}
template <typename T>
bool NodeDynamic<T>::removeChildNode(NodeDynamic<T>* childNode)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i] == childNode)
        {
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}
