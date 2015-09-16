// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// main.cpp
// Driver program

#include "network.h"
#include "traffic.h"
#include "solution.h"

int main()
{
	Network network("9N17L.top");
	network.print();

	Traffic traffic("9N17L.dem", &network);
	traffic.print();

	Solution solution(&network, &traffic);
	solution.print();

	cin.get();
}
