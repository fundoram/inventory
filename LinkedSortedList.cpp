/** ADT sorted list: Link-based implementation.
@file LinkedSortedList.cpp */
#ifndef _LINKED_SORTED_LIST_CPP
#define _LINKED_SORTED_LIST_CPP
#include "LinkedSortedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType & anEntry) const
{
	Node<ItemType>* prev = nullptr;
	Node<ItemType>* curr = headPtr;

	if (headPtr == nullptr || headPtr->getItem() == anEntry)
		return nullptr;
	while (curr != nullptr)
	{
		if (curr->getItem() == anEntry)
			return prev;
		prev = curr;
		curr = curr->getNext();
	}
	return nullptr;
}

// Locates the node at a given position within the chain.
template <class ItemType>
Node < ItemType > * LinkedSortedList<ItemType>::getNodeAt(int position) const
{
	if (position < 1)
		return nullptr;
	Node<ItemType>* curr = headPtr;
	int pos = 1;
	while (curr != nullptr && pos < position)
	{
		curr = curr->getNext();
		pos++;
	}
	return curr;
}

// Returns a pointer to a copy of the chain to which origChainPtr points.
template <class ItemType>
Node < ItemType > * LinkedSortedList<ItemType>::copyChain(const Node < ItemType > *origChainPtr)
{
	Node<ItemType>* top = nullptr;
	Node<ItemType>* newNode;
	Node<ItemType>* cur = nullptr;
	while (origChainPtr != nullptr)
	{
		newNode = new Node<Itemtype>(origChainPtr->getItem);
		if (top == nullptr)
		{
			cur = top = newNode;
		}
		else
		{
			cur->setNext(newNode);
			cur = newNode;
		}
		origChainPtr = origChainPtr->getNext();
	}
	return top;
}

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList()
{
	headPtr = nullptr;
	itemCount = 0;
}

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList < ItemType > &aList)
{
	headPtr = nullptr;
	itemCount = 0;
	headptr = copyChain(aList);
}

template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
	clear();
}

template <class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType & newEntry)
{
	Node<ItemType>* prev = nullptr;
	Node<ItemType>* curr = headPtr;
	Node<ItemType>* newNode = new Node<ItemType>(newEntry);
	while (curr != nullptr && newEntry > curr->getItem())
	{
		prev = curr;
		curr = curr->getNext();
	}
	if (prev == nullptr)
	{
		newNode->setNext(headPtr);
		headPtr = newNode;
	}
	else
	{
		newNode->setNext(curr);
		prev->setNext(newNode);
	}
	itemCount++;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType & anEntry)
{
	Node<ItemType>* prev = getNodeBefore(anEntry);
	Node<ItemType>* curr;
	if (isEmpty())
		return false;
	if (prev == nullptr)
	{
		if (headPtr->getItem() == anEntry)
		{
			curr = headPtr;
			headPtr = curr->getNext();
			curr->setNext(nullptr);
			delete curr;
		}
		else
			return false;
	}
	else
	{
		curr = prev->getNext();
		prev->setNext(curr->getNext());
		curr->setNext(nullptr);
		delete curr;
	}
	itemCount--;
	return true;

}

template <class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType & newEntry) const
{
	int counter = 0;
	Node<ItemType>* curr = headPtr;
	while (curr != nullptr && newEntry > curr->getItem())
	{
		counter++;
		curr = curr->getNext();
	}
	if (curr == nullptr || curr->getItem() != newEntry)
		return -1;
	return counter;
}

// The following methods are the same as given in ListInterface:
template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
	return itemCount;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
	Node<ItemType>* prev;
	Node<ItemType>* curr;
	if (position <= itemCount)
	{
		prev = getNodeAt(position - 1);
		if (prev == nullptr)
			return removeSorted(headPtr->getItem());
		else
		{
			curr = prev->getNext();
			return removeSorted(curr->getItem());
		}
	}
	else
		return false;
}

template <class ItemType>
void LinkedSortedList<ItemType>::clear()
{
	Node<ItemType> * deletePtr;
	while (headPtr != nullptr)
	{
		deletePtr = headPtr;
		headPtr = headPtr->getNext();
		delete deletePtr;
	}
}

template <class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw (PrecondViolatedExcep)
{
	if (position > itemCount)
		throw("Invalid position");
	Node<ItemType>* curr = getNodeAt(position);
	return curr->getItem();
}

#endif