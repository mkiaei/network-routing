// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// heap.h
// Declaration of heap data structure

#ifndef _HEAP_
#define _HEAP_

#include "util.h"

typedef struct
{
	int index;
	double key;
} Element;

class Heap
{
	int *heap;
	Element *elements;
	int size;

	void heapifyDown(int root);
	void heapifyUp(int root);
	void swapElements(int i, int j);

public:
	Heap(vector<int> &hp, vector<Element> &el);
	~Heap();
	void buildHeap();
	void changeKey(int idx, double new_key);
	int pop();
	int empty();
	void print();
};

#endif
