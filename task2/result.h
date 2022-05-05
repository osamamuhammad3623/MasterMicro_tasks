#ifndef _RESULT_H_
#define _RESULT_H_

#include <string>
#include "topology.h"
#include <vector>

typedef vector<Topology> TopologyList;

class Result{
public:
    vector<pair<Topology, DeviceList>> topology_device_vector;

    /* Methods */

    /*
    Description: A function that reads a JSON file and returns topologies and devices in that file
            - Input: file name (relative/absolute path)
            - Output: Result object containing topologies and devices in the JSON file
    */
    Result readJSON(string file_name);

    Result writeJSON(string TopologyID);

    /*
    Description: A function that iterates through vector of pairs of connected devices (topologies),
                    and returns TopologyList of all topologies found
    */
    TopologyList queryTopologies();

    /*
    Description: A function to delete a specific topology and
                    return updated topology_device_vector in a new Result object
    */
    Result deleteTopology(string topology_id);

    /*
    Description: A function that returns all devices connected together in a specific topoligy
    */
    DeviceList queryDevices(string topology_id);

    DeviceList queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID);

    Result();
    ~Result();
};

#endif /* _RESULT_H_ */