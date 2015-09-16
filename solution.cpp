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
	work_paths = NULL;
}
/******************************************************************************/

// Solution constructor
// Arguments: pointers to network and traffic objects
Solution::Solution(Network *net, Traffic *traff)
{
	network = net;
	traffic = traff;
	work_paths = new list<int>[traffic->num_demands];

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
		//cout << "dijkstra " << traffic->demands[k].id << endl;
		work_paths[k] = network->dijkstra(source, dest);
	}
}
/******************************************************************************/

void Solution::print()
{
	cout << "\n*** SOLUTION ***" << endl;

	cout << "-- WORKING ROUTES:" << endl;
	for (int k = 0; k < traffic->num_demands; k++)
	{
		cout << traffic->demands[k].id << " - ";

		for (list<int>::iterator e = work_paths[k].begin(); e != work_paths[k].end(); e++)
		{
			//cout << network->links[*e].id << "  ";
			cout << network->nodes[network->links[*e].node1].id << "-";
			cout << network->nodes[network->links[*e].node2].id << "   ";
		}
		cout << endl;
	}

	cout << endl;
}
/******************************************************************************/

void Solution::print(const char *fileName)
{
	ofstream fcout(fileName);

	fcout << "\n*** SOLUTION ***" << endl;

	fcout << "-- WORKING ROUTES:" << endl;
	for (int k = 0; k < traffic->num_demands; k++)
	{
		fcout << traffic->demands[k].id << "  -  ";

		for (list<int>::iterator e = work_paths[k].begin(); e != work_paths[k].end(); e++)
		{
			//fcout << network->links[*e].id << "  ";
			fcout << network->nodes[network->links[*e].node1].id << "-";
			fcout << network->nodes[network->links[*e].node2].id << "   ";
		}
		fcout << endl;
	}

	fcout << endl;
	fcout.close();
}
/******************************************************************************/

// Solution destructor
Solution::~Solution()
{
	delete [] work_paths;
}
/******************************************************************************/
