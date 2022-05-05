#ifndef _API_H_
#define _API_H_

#include <string>
#include "topology.h"
#include <vector>

typedef vector<Topology> TopologyList;

class API{
public:
    vector<pair<Topology, DeviceList>> topology_devices_vector;

    bool readJSON(string file_name);

    bool writeJSON(string TopologyID);

    TopologyList queryTopologies();

    bool deleteTopology(string topology_id);

    DeviceList queryDevices(string topology_id);

    DeviceList queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID);

    API();
    ~API();
};

#endif /* _API_H_ */