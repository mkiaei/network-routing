// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// traffic.cpp
// Traffic class implementation

#include "traffic.h"

// Traffic constructor: Initialize traffic parameters based on demand file
// Argument: Demands file name
Traffic::Traffic(const char *filename, Network *net)
{
	network = net;
	num_demands = 0;

	cout << "-----------------------------------------" << endl;
	cout << "Traffic" << endl;
	readDemands(filename);

	traffic_matrix.resize(network->num_nodes);
	for (int i = 0; i < network->num_nodes; i++)
		traffic_matrix[i].resize(network->num_nodes, 0);

	for (int i = 0; i < num_demands; i++)
	{
		traffic_matrix[demands[i].node1][demands[i].node2] += demands[i].units;
		traffic_matrix[demands[i].node2][demands[i].node1] += demands[i].units;
	}
}
/******************************************************************************/

// readDemands: Read demand pair from ".dem" file
// Argument: Demands file name
void Traffic::readDemands(const char *filename)
{
	string node1, node2;
	int units, id;
	
	ifstream traffic_file(filename);
	string line, word, name;
	istringstream iss;
	Demand dem;

	if (traffic_file.good())
	{
		do {
			getline(traffic_file, line);
			iss.clear();
			iss.str(line);
			iss >> word;
		} while (word != "DEMAND");

		while (getline(traffic_file, line))
		{
			if (line.size() > 0 && line[0] == 'N')
			{
				iss.clear();
				iss.str(line);
				iss >> name >> node1 >> node2 >> units >> id;
				num_demands += units;
				for (int i = 0; i < units; i++)
				{
					dem.name = name;
					dem.units = 1;
					dem.id = id;
					dem.node1 = network->getNodeIndex(node1);
					dem.node2 = network->getNodeIndex(node2);
					demands.push_back(dem);
				}
			}
		}
	}
	else
	{
		cerr << "Cannot open traffic file!\n";
		cin.get();
		exit(0);
	}	
}
/******************************************************************************/

// print: Print traffic parameters to stdout
void Traffic::print()
{
	cout << "\n**** TRAFFIC ****" << endl;
	cout << "# of demands: " << num_demands << endl;

	for (int i = 0; i < num_demands; i++)
	{
		cout << "Demand " << i << ": " << demands[i].id << "  ";
		cout << network->nodes[demands[i].node1].id << "-";
		cout << network->nodes[demands[i].node2].id << " " << demands[i].units << endl;
	}

	cout << "\nTraffic Matrix:" << endl;
	for(int i = 0; i < network->num_nodes; i++)
	{
		for(int j = 0; j < network->num_nodes; j++)
			cout << traffic_matrix[i][j] << " ";
		cout << endl;
	}
}
/******************************************************************************/
