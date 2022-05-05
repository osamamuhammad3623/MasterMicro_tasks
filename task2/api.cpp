#include "api.h"
#include "json.hpp"
#include "fstream"
using json = nlohmann::json;


bool API::readJSON(string file_name){
    /* read json topology into json object */
    ifstream json_file(file_name);
    json json_object;
    json_file >> json_object;

    /* define API object, topology object */
    Topology topology;

    /* set the id of the topology object to the id we got from json */
    /* no loops, assuming the topology JSON holds info about only one topology */
    topology.set_id(json_object["id"]);

    /* get devices and adding them to the device list */
    DeviceList dv;
    for (int i=0; i< json_object["components"].size(); i++){
        Component c;
        c.set_id(json_object["components"][i]["id"]);
        c.set_type(json_object["components"][i]["type"]);
        dv.push_back(c);
    }

}

bool API::writeJSON(string TopologyID){
    
}

TopologyList API::queryTopologies(){
    TopologyList list;
    for (int i=0; i< this->topology_devices_vector.size(); i++){
        list.push_back(topology_devices_vector[i].first);
    }

    return list;
}

DeviceList API::queryDevices(string topology_id){
    DeviceList dv_list;
    for (int i=0; i< this->topology_devices_vector.size(); i++){
        if (topology_devices_vector[i].first.get_id() == topology_id){
            dv_list = topology_devices_vector[i].second;
            break;
        }
    }

    return dv_list;
}

bool API::deleteTopology(string topology_id){

    for (int i=0; i< this->topology_devices_vector.size(); i++){
        if (topology_devices_vector[i].first.get_id() == topology_id){
            /* if topology id found, replace it with the last item in the vector, then pop back */
            /* search in O(n) and delete in O(1) */
            int last_index = topology_devices_vector.size()-1;
            topology_devices_vector[i] = topology_devices_vector[last_index];
            topology_devices_vector.pop_back();
            return true;   
        }
    }

    return false;
}



API::API(){

}

API::~API(){

}