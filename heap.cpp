// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// heap.cpp
// Implementation of heap data structure

#include "heap.h"

Heap::Heap(int n)
{
	heap = new int[n+1];
	elements = new Element[n];
	size = 0;
}
/******************************************************************************/

Heap::Heap(int *hp, Element *el, int size_)
{
	elements = el;
	heap = hp;
	size = size_;
}
/******************************************************************************/

void Heap::heapifyDown(int root)
{
	int child = 2 * root;
	int parent = root;

	while (child <= size)
	{
		if (child < size && elements[heap[child]].key > elements[heap[child+1]].key)
			child++;

		if (elements[heap[parent]].key <= elements[heap[child]].key) 
			break;
		else
		{ 
			swap(parent, child);
			parent = child;
			child *= 2;
		}
	}
}
/******************************************************************************/

void Heap::heapifyUp(int root)
{
	double root_key = elements[heap[root]].key;
	int parent = root/2;
	int child = root;

	while (parent > 0)
	{
		if (root_key >= elements[heap[parent]].key) 
			break;
		else
		{ 
			swap(parent, child);
			child = parent;
			parent = parent/2;
		}
	}
}
/******************************************************************************/

void Heap::buildHeap()
{
	for (int i = size/2; i > 0; i--)
		heapifyDown(i);
}
/******************************************************************************/

int Heap::pop()
{
	swap(1, size);
	size--;
	heapifyDown(1);
	return heap[size + 1];
}
/******************************************************************************/

void Heap::changeKey(int idx, double new_key)
{
	if (elements[idx].key > new_key)
	{
		elements[idx].key = new_key;
		heapifyUp(elements[idx].index);
	} 
	else
	{
		elements[idx].key = new_key;
		heapifyDown(elements[idx].index);
	}
}
/******************************************************************************/

int Heap::empty()
{
	return (size == 0);
}
/******************************************************************************/

void Heap::print()
{
	cout << "\n Heap size: " << size << endl;
	for (int i = 1 ; i <= size ; i++)
		cout << heap[i] << ":" << elements[heap[i]].key << " ";
	cout << endl;
}
/******************************************************************************/

void Heap::swap(int i, int j)
{
	std::swap(heap[i], heap[j]);
	elements[heap[i]].index = i;
	elements[heap[j]].index = j;
}
/******************************************************************************/

Heap::~Heap()
{
	delete [] elements;
	delete [] heap;
}
/******************************************************************************/
