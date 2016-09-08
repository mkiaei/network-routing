// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// solution.h
// Solution class declaration

#ifndef _SOLUTION_
#define _SOLUTION_

#include "network.h"
#include "traffic.h"

class Solution
{
public:
	Network *network;
	Traffic *traffic;
	list<int> *work_paths;

	Solution();
	Solution(Network *net, Traffic *traff);
	~Solution();

	void calculateWorkingPaths();

	/// Print the solution to an output stream
	void print(ostream &out);
};

#endif
