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

int main(int argc, char * argv[])
{
    string top_filename, dem_filename;
    
    if (argc == 3)
    {
        top_filename = argv[1];
        dem_filename = argv[2];
    }
    else
    {
        top_filename = "9N17L.top";
        dem_filename = "9N17L.dem";
    }

    Network network(top_filename.data());
    network.print();

    Traffic traffic(dem_filename.data(), &network);
    traffic.print();

    Solution solution(&network, &traffic);
    solution.print(cout);

    cin.get();
}
