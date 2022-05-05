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

    /* setter and getter for id */
    void set_id(string id);
    string get_id();

};

#endif /* _TOPOLOGY_H_ */
