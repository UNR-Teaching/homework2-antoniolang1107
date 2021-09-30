#ifndef LINKED_STACK
#define LINKED_STACK

template<class ItemType>
class LinkedStack {
public:
    bool isEmpty();
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
};
#endif