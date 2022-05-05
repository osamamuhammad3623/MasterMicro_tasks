#include "result.h"
#include "json.hpp"
#include "fstream"
using json = nlohmann::json;


Result Result::readJSON(string file_name){
    /* read json topology into json object */
    ifstream json_file(file_name);
    json json_object;
    json_file >> json_object;

    /* define Result object, topology object */
    Result r;
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

    r.topology_device_vector.push_back(make_pair(topology, dv));
    return r;
}

Result Result::writeJSON(string TopologyID){
    
}

TopologyList Result::queryTopologies(){
    TopologyList list;
    for (int i=0; i< this->topology_device_vector.size(); i++){
        list.push_back(topology_device_vector[i].first);
    }

    return list;
}

DeviceList Result::queryDevices(string topology_id){
    DeviceList dv_list;
    for (int i=0; i< this->topology_device_vector.size(); i++){
        if (topology_device_vector[i].first.get_id() == topology_id){
            dv_list = topology_device_vector[i].second;
            break;
        }
    }

    return dv_list;
}

Result Result::deleteTopology(string topology_id){
    Result updated_result; 
    for (int i=0; i< this->topology_device_vector.size(); i++){
        // if it the current id is not the one, add it to Result object
        if (topology_device_vector[i].first.get_id() != topology_id){
            updated_result.topology_device_vector.push_back(topology_device_vector[i]);
        }else{
            // ignore, do nothing
        }
    }

    return updated_result;
}



Result::Result(){

}

Result::~Result(){

}