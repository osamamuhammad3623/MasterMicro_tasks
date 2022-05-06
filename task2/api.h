#ifndef _API_H_
#define _API_H_

#include <string>
#include "topology.h"
#include <vector>

typedef vector<Topology> TopologyList;

class API{
public:
    vector<Topology> topologies_vector;

    /**
     *  Description: Read a topology from a given JSON file and store it in the memory.
    */
    bool readJSON(string file_name);

    /**
     *  Description:Write a given topology from the memory to a JSON file named: output_json_file.json
    */
    bool writeJSON(string TopologyID);

    /**
     *  Description: A function that returns a list of topologies found in memory
    */
    TopologyList queryTopologies();

    /**
     *  Description: A function to delete a given topology from memory
    */
    bool deleteTopology(string topology_id);

    /**
     *  Description: A function that return a list of components in a given topology 
    */
    DeviceList queryDevices(string topology_id);

    /**
     *  Description: A function that return a list of components that are connected to a given netlist node in a given topology
    */
    DeviceList queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID);

    API();
    ~API();
};

#endif /* _API_H_ */