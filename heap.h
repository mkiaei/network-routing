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

	void heapfyDown(int root);
	void heapfyUp(int root);
	void swap(int i, int j);

public:
	Heap(int n);
	Heap(int *h, Element *e, int n);
	~Heap();
	void buildHeap();
	void changeKey(int e, double newKey);
	int deleteMin();
	int getSize();
	void print();
};

#endif
