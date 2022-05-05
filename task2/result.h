#ifndef _RESULT_H_
#define _RESULT_H_

#include <string>
#include "topology.h"
#include <vector>

typedef vector<Topology> TopologyList;

class Result{
public:
    /* attributes */
    TopologyList topologies;
    DeviceList devices;

    /* Methods */
    Result readJSON(string file_name);
    Result writeJSON();
    TopologyList queryTopologies();
    Result deleteTopology(string topology_id);
    DeviceList queryDevices(string topology_id);
    DeviceList queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID);

    Result();
    ~Result();
};

#endif /* _RESULT_H_ */