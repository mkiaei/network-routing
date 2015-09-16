# network-routing

------------
DESCRIPTION
------------
Simulation framework for demand routing in a mesh network.\\
version 1.0 2015-08-30\\
Author: Mohammad Kiaei

-----
NOTES
-----
- A heap implementation of Dijkstra's shortest path algorithm is used for routing demands.
- Network topology is read from a ".top" file.
- Demand set is read from a ".dem" file.
- Program is tested in Visual C++ Express 2010 and g++ version 4.8.4.

------------
CONTENTS
------------
README		This file
C++ files:
    network.cpp, network.h      Network class code
    traffic.cpp, traffic.h      Traffic class code
    solution.cpp, solution.h    Solution class code
    heap.cpp, heap.h            Heap data structure code
    util.cpp, util.h            Utility functions code

Sample topology files
    COST239.top                 COST-239 Topology file
    9N17L.top                   Topology file for a network with 9 nodes and 17 links

Sample demand files
    9N17L.dem                   Demand set for 9N17L network

