#include "api.h"
#include "json.hpp"
#include "fstream"
#include <iostream>
using namespace std;
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
    for (int i=0; i< json_object["components"].size(); i++){
        Component c;
        /* get component type & id */
        c.set_id(json_object["components"][i]["id"]);
        c.set_type(json_object["components"][i]["type"]);
        /* get component type info */
        if (json_object["components"][i]["type"] == "resistor"){
            float d, min_v, max_v;
            d = json_object["components"][i]["resistance"]["default"];
            min_v = json_object["components"][i]["resistance"]["min"];
            max_v = json_object["components"][i]["resistance"]["max"];
            c.set_values(d,min_v,max_v);

        }else if (json_object["components"][i]["type"] == "nmos"){
            float d, min_v, max_v;
            d = json_object["components"][i]["m(l)"]["default"];
            min_v = json_object["components"][i]["m(l)"]["min"];
            max_v = json_object["components"][i]["m(l)"]["max"];
            c.set_values(d,min_v,max_v);
        }

        /* get component netlist info */
        json net_list = json_object["components"][i]["netlist"];
        c.set_netlist(net_list);
        topology.add_device(c);
    }

    /* save the loaded topology in memory before returning it */
    this->topologies_vector.push_back(topology);
    return true;
}

bool API::writeJSON(string TopologyID){
    for (int i=0; i< this->topologies_vector.size(); i++){
        if (this->topologies_vector[i].get_id() == TopologyID){

            json json_object;
            Topology topo = topologies_vector[i];

            /* get complete info about the topology components */
            json_object["id"] = topo.get_id();
            for (int j=0; j<topo.get_devices().size(); j++){
                Component current_c = topo.get_devices()[j];
                json_object["components"][j]["id"] = current_c.get_id();
                json_object["components"][j]["type"] = current_c.get_type();
                if (current_c.get_type() == "resistor"){
                    json_object["components"][j]["resistance"]["default"] = current_c.get_default_value();
                    json_object["components"][j]["resistance"]["min"] = current_c.get_min_value();
                    json_object["components"][j]["resistance"]["max"] = current_c.get_max_value();
                }else if (current_c.get_type() == "nmos"){
                    json_object["components"][j]["m(l)"]["default"] = current_c.get_default_value();
                    json_object["components"][j]["m(l)"]["min"] = current_c.get_min_value();
                    json_object["components"][j]["m(l)"]["max"] = current_c.get_max_value();
                }

                json_object["components"][j]["netlist"] = current_c.get_netlist();
            }

            ofstream output_file("output_json_file.json");
            output_file << json_object << "\n";
            return true;
        }
    }
    return false;
}

TopologyList API::queryTopologies(){
    return this->topologies_vector;
}

DeviceList API::queryDevices(string topology_id){
    DeviceList dv_list;
    for (int i=0; i< this->topologies_vector.size(); i++){
        if (topologies_vector[i].get_id() == topology_id){
            dv_list = topologies_vector[i].get_devices();
            break;
        }
    }

    return dv_list;
}

bool API::deleteTopology(string topology_id){

    for (int i=0; i< this->topologies_vector.size(); i++){
        if (topologies_vector[i].get_id() == topology_id){
            /* if topology id found, replace it with the last item in the vector, then pop back */
            /* search in O(n) and delete in O(1) */
            int last_index = topologies_vector.size()-1;
            topologies_vector[i] = topologies_vector[last_index];
            topologies_vector.pop_back();
            return true;   
        }
    }

    return false;
}

DeviceList API::queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID){
    DeviceList dv = {};
    for (int i=0; i< this->topologies_vector.size(); i++){
        if (topologies_vector[i].get_id() == TopologyID){
            Topology topo = topologies_vector[i];
            
            for (int j=0; j<topo.get_devices().size(); j++){
                Component current_component = topo.get_devices()[j];
                json current_netlist = current_component.get_netlist();

                for (auto it: current_netlist){
                    if (it == NetlistNodeID){
                        dv.push_back(current_component);
                    }
                }
                return dv;
            }
        }
    }

    // if not found, just return empty DeviceList 
    return dv;
}

API::API(){

}

API::~API(){

}