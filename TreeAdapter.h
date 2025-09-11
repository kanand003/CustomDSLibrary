#pragma once
#include "CustomTree.h"
#include "IDataStructure.h"

class TreeAdapter : public IDataStructure
{
	CustomTree<int> tree;
public:
	void insert(int value) override
	{
        tree.Insert(value);
	}
    void remove(int value) override 
    {
        tree.Remove(value);
    }

    void display() override 
    {
        tree.Display();
    }

    bool search(int value) override 
    {
        return tree.search(value);
    }

    void clear() override 
    {
        tree.clear();
    }
};