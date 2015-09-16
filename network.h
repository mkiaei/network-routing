// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// network.h
// Network class declaration

#ifndef _NETWORK_
#define _NETWORK_

#include "util.h"
#include "heap.h"

typedef struct
{
	int x, y;
	int size;
	char id[10];
} Node;

typedef struct
{
	int node1;
	int node2;
	int cost;
	int id;
	char name[10];
} Link;

typedef struct
{
	int node;
	int edge;
} ListElement;

class Network
{
public:
	int num_nodes, num_links;
	list<ListElement> *adj_list;
	vector<vector<int> > adj_matrix;
	vector<Link> links;
	vector<Node> nodes;

	Network();
	Network(const char *top_fileName);
	~Network();

	int getNodeIndex(const char *id);
	int getLinkIndex(int id);
	void print();
	void readNetwork(const char *fileName);
	list<int> dijkstra(int src, int dst);
};

#endif
