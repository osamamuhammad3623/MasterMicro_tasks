#include "result.h"
#include <iostream>
using namespace std;

int main(){
    Result r, result;
    result = r.readJSON("topology.json");

    cout << "readJSON test\n";
    for (int i=0; i<result.topology_device_vector.size(); i++){
        cout << "Topology " << result.topology_device_vector[i].first.get_id() << ":\n";
        for (int j=0; j< result.topology_device_vector[i].second.size();j++){
            cout << "Component id: " << result.topology_device_vector[i].second[j].get_id() << "\n";
            cout << "Component type: " << result.topology_device_vector[i].second[j].get_type() << "\n";
        }
    }
    cout << "\n\n";


    cout << "queryTopologies test\n";
    TopologyList t_l = result.queryTopologies();
    for (auto i: t_l){
        cout<< "Topology: " << i.get_id() << "\n";
    }
    cout << "\n\n";


    cout << "queryDevices test\n";
    DeviceList dv_l = result.queryDevices("top1");
    for (auto i: dv_l){
        cout<< "Device in top1: " << i.get_id() << "-->" << i.get_type() << "\n";
    }
    cout << "\n\n";


    cout << "deleteTopology test\n";
    Result new_result = result.deleteTopology("top1");
    if (new_result.topology_device_vector.size() == 0){
        cout << "Empty vector\n";
    }else{
        cout << "Nothing deleted\n";
    }
    cout << "\n\n";

    
}