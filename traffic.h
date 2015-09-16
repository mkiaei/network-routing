// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// traffic.h
// Traffic class declaration

#ifndef _TRAFFIC_
#define _TRAFFIC_

#include "network.h"

struct Demand
{
	int node1, node2;
	int units;
	string name;
	int id;
};

class Traffic
{
	void readDemands(const char *fileName);
public:
	Network *network;
	vector<Demand> demands;
	vector<vector<int> > traffic_matrix;
	int num_demands;

	Traffic() {};
	Traffic(const char *fileName, Network *net);

	void print();
};

#endif
