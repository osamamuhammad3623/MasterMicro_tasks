#ifndef _TOPOLOGY_H_
#define _TOPOLOGY_H_

#include <string>
#include <vector>
#include "component.h"
using namespace std;


typedef vector<Component> DeviceList;

class Topology{
private:
    string topology_id;
    DeviceList devices;

public:
    Topology();
    ~Topology();

    void set_id(string id);
    string get_id();

    /**
     *  Description: A function that return the list of components in the topology
    */
    DeviceList get_devices();

    /**
     *  Description: A function to add (connect) a component to the topology
    */
    void add_device(Component c);
};

#endif /* _TOPOLOGY_H_ */
