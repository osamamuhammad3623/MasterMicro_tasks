#include "api_test.h"
#include "api.h"
#include <iostream>
using namespace std;

#define PASSED      cout << "PASSED\n"
#define NOT_PASSED  cout << "NOT PASSED\n"

API api;
Topology test_topo;

//Tests must be run sequential because they depend on each other

void API_Test::readJSON_test(){
    cout << "\nreadJSON API test --> ";

    string file_name = "topology_test.json";
    test_topo = api.readJSON(file_name);
    if (test_topo.get_id() == "top_test_2"){
        for (auto device: test_topo.get_devices()){
            if (device.get_id() == "test_res1"){
                PASSED;
                return;
            }
        }
    }
    NOT_PASSED;
}

void API_Test::writeJSON_test(){
    cout << "\nwriteJSON API test --> ";

    /* create a Component */
    Component test_c;
    test_c.set_id("test_component");
    test_c.set_type("resistor");
    test_c.set_values(15,10,20);
    vector<pair<string,string>> v = {make_pair("key1", "value1")};
    test_c.set_netlist(v);
    
    test_topo.set_id("new_id_test");
    test_topo.add_device(test_c); // add the Component to the topology
    /* add topology to API class attribute */
    api.topology_devices_vector.push_back(make_pair(test_topo, DeviceList()));

    bool passed = api.writeJSON("new_id_test");
    if (passed){PASSED;}
    else {NOT_PASSED;}
}

void API_Test::queryTopologies_test(){
    cout << "\nqueryTopologies API test --> ";
    /* create 2 more topologies (+1 pushed in writeJSON API) */
    Topology t1,t2;
    t1.set_id("topo_test_n");
    t2.set_id("topo_test_2");
    /* create 4 components and add them to 2 DeviceLists */
    Component c1,c1_2, c2, c2_2;
    c1.set_id("test_com_1");
    c2.set_id("test_com_3");
    c1_2.set_id("test_com_2");
    c2_2.set_id("test_com_4");
    DeviceList dv1 = {c1,c1_2};
    DeviceList dv2 = {c2,c2_2};
    /* link the DeviceLists with the created topologies */
    api.topology_devices_vector.push_back(make_pair(t1, dv1));
    api.topology_devices_vector.push_back(make_pair(t2, dv2));

    if (api.queryTopologies().size() == 3){
       PASSED;
    }else{
        NOT_PASSED;
    }
}

void API_Test::deleteTopology_test(){
    cout << "\ndeleteTopology API test --> ";
    api.deleteTopology("topo_test_n");
    // to check that the topology is deleted, queryTopologies should be 3-1 = 2
    if (api.queryTopologies().size() == 2){
       PASSED;
    }else{
        NOT_PASSED;
    }
}

void  API_Test::queryDevices_test(){
    cout << "\nqueryDevices API test --> ";
    DeviceList dv = api.queryDevices("topo_test_2");
    for (auto it: dv){
        if (!(it.get_id() == "test_com_3" || it.get_id() == "test_com_4")){
            NOT_PASSED;
            return;
        }
    }

    PASSED;
}

void  API_Test::queryDevicesWithNetlistNode_test(){
    
}

API_Test::API_Test(){

}

API_Test::~API_Test(){

}