#include <string>
#include "topology.h"
#include <vector>

typedef vector<Topology> TopologyList;

class Result{
private:
    TopologyList topologies;
    DeviceList devices;

public:
    Result readJSON(string file_name);
    //Result writeJSON();
    TopologyList queryTopologies();
    Result deleteTopology(string topology_id);
    DeviceList queryDevices(string topology_id);
    DeviceList queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID);
};
