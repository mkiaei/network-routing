// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// solution.cpp
// Solution class implementation

#include "solution.h"

// Solution default constructor
Solution::Solution()
{
	network = NULL;
	traffic = NULL;
}
/******************************************************************************/

// Solution constructor
// Arguments: pointers to network and traffic objects
Solution::Solution(Network *net, Traffic *traff)
{
	network = net;
	traffic = traff;
	work_paths.resize(traffic->num_demands);

	calculateWorkingPaths();
}
/******************************************************************************/

// calculateWorkingPaths: Calculate shortest path for all demands pairs in the network
void Solution::calculateWorkingPaths()
{
	cout << "Routing the demands by dijkstra " << endl << endl;
	int source, dest;
	for (int k = 0; k < traffic->num_demands; k++)
	{
		source = traffic->demands[k].node1;
		dest = traffic->demands[k].node2;
		work_paths[k] = network->dijkstra(source, dest);
	}
}
/******************************************************************************/

void Solution::print(ostream &out)
{
	out << "\n*** SOLUTION ***" << endl;

	out << "-- WORKING ROUTES:" << endl;
	for (int k = 0; k < traffic->num_demands; k++)
	{
		out << traffic->demands[k].id << " - ";

		for (list<int>::iterator e = work_paths[k].begin(); e != work_paths[k].end(); e++)
		{
			//out << network->links[*e].id << "  ";
			out << network->nodes[network->links[*e].node1].id << "-";
			out << network->nodes[network->links[*e].node2].id << "   ";
		}
		out << endl;
	}

	out << endl;
}
/******************************************************************************/

// Solution destructor
Solution::~Solution()
{
}
/******************************************************************************/
