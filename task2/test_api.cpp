#include "result.h"
#include <iostream>
using namespace std;

int main(){
    Result r, result;
    result = r.readJSON("topology.json");

    for (int i=0; i< result.devices.size(); i++){
        cout << "Device " << i << " ID: " << result.devices[i].get_id() << "\n";
        cout << "Device " << i << " type: " << result.devices[i].get_type() << "\n";
    }

    for (int i=0; i< result.topologies.size(); i++){
        cout << "Topology " << i << " ID: " << result.topologies[i].get_id() << "\n";
    }
}