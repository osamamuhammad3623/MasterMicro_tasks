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

    DeviceList get_devices();
    void add_device(Component c);
};

#endif /* _TOPOLOGY_H_ */
