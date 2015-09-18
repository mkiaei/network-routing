// Network traffic routing
// 
// Mohammad Kiaei
// August 2015
//
// network.cpp
// Network class implementation

#include "network.h"

// Network constructor: Initialize network parameters based on topology file
// Argument: Topology file name
Network::Network(const char *filename)
{
	num_nodes = 0;
	num_links = 0;

	readNetwork(filename);

	adj_matrix.resize(num_nodes);
	for (int i = 0; i < num_nodes; i++)
		adj_matrix[i].resize(num_nodes, 0);

	adj_list = new list<ListElement> [num_nodes];

	for (int i = 0; i < num_links; i++)
	{
		adj_matrix[links[i].node1][links[i].node2] = i;
		adj_matrix[links[i].node2][links[i].node1] = i;

		ListElement key1 = {links[i].node2, i};
		ListElement key2 = {links[i].node1, i};
		adj_list[links[i].node1].push_back(key1);
		adj_list[links[i].node2].push_back(key2);
	}
}
/******************************************************************************/

// readNetwork: Read network parameters from ".top" file
// Argument: Topology file name
void Network::readNetwork(const char *filename)
{
	char id[15], size_x[10], size_y[10], size[10], cost[10];
	string line, word;
	istringstream iss;
	ifstream network_file(filename);

	if (network_file.good())
	{
		cout << "Reading Network Topology from .top file" << endl;

		//cout << "Setting Nodes..." << endl;
		do
		{
			getline(network_file, line);
			iss.clear();
			iss.str(line);
			iss >> word;
		} while (word != "NODE");
		word.clear();
		
		getline(network_file, line);
		while (line.size() > 0 && line[0] == 'N')
		{
			iss.clear();
			iss.str(line);
			Node node;
			iss >> node.id >> size_x >> size_y >> size;

			node.x = atoi(size_x);
			node.y = atoi(size_x);
			node.size = atoi(size);
			nodes.push_back(node);
			getline(network_file, line);
		}

		num_nodes = nodes.size();

		do
		{
			getline(network_file, line);
			iss.clear();
			iss.str(line);
			iss >> word;
		} while (word != "LINK");

		getline(network_file, line);
		while (line.size() > 0 && line[0] == 'L')
		{
			iss.clear();
			iss.str(line);
			Link link;
			iss >> link.name >> cost >> id;
			link.cost = atoi(cost);
			link.id = atoi(id);

			string str(link.name);
			str = str.substr(str.find('_') + 1);
			link.node1 = atoi(str.data());
			str = str.substr(str.find('_') + 1);
			link.node2 = atoi(str.data());

			links.push_back(link);
			getline(network_file, line);
		}

		num_links = links.size();
	}
	else
	{
		cerr << "Cannot open .top file!\n";
		cin.get();
		exit(0);
	}
}
/******************************************************************************/

// dijkstra: Dijkstra shortest path algorithm
// Arguments: source and destination nodes
list<int> Network::dijkstra(int src, int dst)
{
	int edge, x, y;
	vector<int> previous(num_nodes);

	int *heap_array = new int[num_nodes + 1];
	Element *elements = new Element[num_nodes];
	Heap heap(heap_array, elements, num_nodes);
	list<int> path;

	for (int i = 0; i < num_nodes; i++)
	{
		heap_array[i+1] = i;
		elements[i].index = i+1;
		elements[i].key = DBL_MAX;
		previous[i] = -1;
	}

	heap.changeKey(src, 0);
	//heap.print();

	while (!heap.empty())
	{
		x = heap.pop();
		if (x == dst) 
			break;

		list<ListElement>::iterator current;
		for (current = adj_list[x].begin(); current != adj_list[x].end(); current++)
		{
			edge = current->edge;
			y = links[edge].node1;
			if (y == x)
				y = links[edge].node2;

			if (elements[x].key + links[edge].cost < elements[y].key)
			{
				heap.changeKey(y, elements[x].key + links[edge].cost);
				previous[y] = edge;
			}
		}
	}

	y = dst;
	//cout << "Path - ";
	do
	{
		edge = previous[y];
		x = links[edge].node1;
		if (x == y)
			x = links[edge].node2;
		//cout << edge << ":" << x << "," << y << " ";
		path.push_back(edge);
		y = x;
	} while (x != src);
	//cout << endl;

	return path;
}
/******************************************************************************/

// getNodeIndex: Find the node index based on node id
// Argument: node id
int Network::getNodeIndex(const char *id)
{
	for (int i = 0; i < num_nodes; i++)
	{
		if (strcmp(nodes[i].id, id) == 0)
			return i;
	}
	cerr << "Invalid Node Index!\n";
	return -1;
}
/******************************************************************************/

// getNodeIndex: Find the link index based on link id
// Argument: link id
int Network::getLinkIndex(int id)
{
	for (int i = 0; i < num_links; i++)
	{
		if (links[i].id == id)
			return i;
	}
	cerr << "Invalid Link Index!\n";
	return -1;
}
/******************************************************************************/

// print: Print network parameters to stdout
void Network::print()
{
	cout << "\n**** NETWORK ****" << endl;
	cout << "# of nodes: " << num_nodes << "   # of links: " << num_links << endl;

	cout << "\nLinks: " << endl;
	for (int i = 0; i < num_links; i++)
	{
		cout << links[i].id << " - " << nodes[links[i].node1].id << " ";
		cout << nodes[links[i].node2].id << "   "<< links[i].cost << endl;
	}

	cout << "\nAdjacency Matrix:" << endl;
	for (int i = 0; i < num_nodes; i++)
	{
		for (int j = 0; j < num_nodes; j++)
			cout << adj_matrix[i][j] << " ";
		cout << endl;
	}

	cout << "\nAdjacency List:" << endl;
	for (int i = 0; i < num_nodes; i++)
	{
		cout << nodes[i].id;
		cout << " -> ";
		list<ListElement>::iterator current;
		for (current = adj_list[i].begin(); current != adj_list[i].end(); current++)
			cout << (*current).node << " - ";
		cout << endl;
	}
}
/******************************************************************************/

// Network destructor
Network::~Network()
{
	delete [] adj_list;
}
/******************************************************************************/
