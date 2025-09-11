#include <iostream>

class IDataStructure {
public:
    virtual void insert(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void display() = 0;
    virtual bool search(int value) = 0;
    virtual void clear() = 0;
};