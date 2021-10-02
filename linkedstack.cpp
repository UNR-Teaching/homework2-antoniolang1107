template<class ItemType>
LinkedStack<ItemType>::LinkedStack() {
    topPtr = nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    if (topPtr == nullptr || topPtr == 0x0)
        return true;
    else
        return false;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry) {
    Node<ItemType>* newNode = new Node<ItemType>(newEntry);
    newNode->setNext(topPtr);
    topPtr = newNode;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    if (isEmpty()) {
        return false;
    }
    else {
        Node<ItemType>* nodeToDelete = topPtr;
        topPtr = topPtr->getNext();
        delete nodeToDelete;
        return true;
    }
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    if (topPtr == nullptr) {
        return NULL;
    }
    else {
        return topPtr->getItem();
    }
}
