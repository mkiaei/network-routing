## Network Routing
 A simulation framework for demand routing in mesh networks  
 Author: **Mohammad Kiaei**  
 Version 1.0  
 Date: 2015-08-30

## Notes
- A heap implementation of Dijkstra's shortest path algorithm is used for routing demands.
- Network topology is read from a ".top" file.
- Demand set is read from a ".dem" file.
- Program is tested in Visual C++ 2010 Express and g++ version 4.8.4.

## Contents
* C++ files
  * **network.cpp, network.h**:      Network class implementation
  * **traffic.cpp, traffic.h**:      Traffic class implementation
  * **solution.cpp, solution.h**: Solution class implementation
  * **heap.cpp, heap.h**: Heap data structure
  * **util.cpp, util.h**: Utility functions
  * **main.cpp**: Driver program

* Sample topology files:
  * **COST239.top**: Topology file for COST-239 network
  * **9N17L.top**: Topology file for a network with 9 nodes and 17 links

* Sample demand file:
  * **9N17L.dem**: Demand set for 9N17L network
