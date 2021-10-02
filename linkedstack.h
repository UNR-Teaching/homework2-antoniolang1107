#ifndef LINKED_STACK
#define LINKED_STACK

#include "stackinterface.h"
#include "node.h"

using namespace std;

template<class ItemType> 
class LinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType>* topPtr;
public:
    LinkedStack();
    //LinkedStack(LinkedStack& copyStack);
    bool isEmpty () const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
    ~LinkedStack() { }
};

#include "linkedstack.cpp"
#endif