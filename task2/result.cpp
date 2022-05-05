#include "result.h"
#include "json.hpp"
#include "fstream"
using json = nlohmann::json;


Result Result::readJSON(string file_name){
    /* read json topology into json object */
    ifstream json_file(file_name);
    json json_object;
    json_file >> json_object;

    /* define Result object, topology object and TobologyList */
    Result r;
    Topology topology;
    TopologyList top_list;

    /* set the id of the topology object to the id we got from json, and add the object to the list */
    topology.set_id(json_object["id"]);
    top_list.push_back(topology);
    r.topologies = top_list;

    /* get the list of devices/components */
    DeviceList dv_list;
    for (int i=0; i< json_object["components"].size(); i++){
        Component c;
        c.set_id(json_object["components"][i]["id"]);
        c.set_type(json_object["components"][i]["type"]);
        dv_list.push_back(c);
    }
    r.devices = dv_list; /* set the device list of the return object to the device list we created */

    return r;
}


Result::Result(){

}

Result::~Result(){

}