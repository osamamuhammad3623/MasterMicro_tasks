#include "api_test.h"
#include <iostream>
using namespace std;

#define PASSED      cout << "PASSED\n"
#define NOT_PASSED  cout << "NOT PASSED\n"

API api;

void API_Test::readJSON_test(){
    cout << "Test 1/6: readJSON test --> ";
    if (api.readJSON("topology_test.json")){
        PASSED;
    }else{
        NOT_PASSED;
    }
}

void API_Test::writeJSON_test(){
    cout << "Test 2/6: writeJSON test --> ";
    if (api.writeJSON("top_test_2")){
        PASSED;
    }else{
        NOT_PASSED;
    }
}

void API_Test::queryTopologies_test(){
    cout << "Test 3/6: queryTopologies test --> ";
    TopologyList list = api.queryTopologies();
    TopologyList expected_result = {api.topologies_vector[0]};

    if (list.size() != expected_result.size()){
        NOT_PASSED;
        return;
    }

    for (int i=0; i< list.size(); i++){
        if (list[i].get_id() != expected_result[i].get_id()){
            NOT_PASSED;
            return;
        }
    }

    PASSED;
}

void API_Test::queryDevices_test(){
    cout << "Test 4/6: queryDevices test --> ";
    Component c1,c2;
    c1.set_id("test_res1");
    c2.set_id("test_m1");
    DeviceList expected_result = {c1,c2};
    DeviceList result = api.queryDevices("top_test_2");

    if (result.size() != expected_result.size()){
        NOT_PASSED;
        return;
    }

    for (int i=0; i< result.size(); i++){
        if (result[i].get_id() != expected_result[i].get_id()){
            NOT_PASSED;
            return;
        }
    }

    PASSED;
}

void  API_Test::queryDevicesWithNetlistNode_test(){
    cout << "Test 5/6: queryDevicesWithNetlistNode test --> ";
    Component c1;
    c1.set_id("test_res1");
    DeviceList expected_result = {c1};

    DeviceList result = api.queryDevicesWithNetlistNode("top_test_2", "test_n1");

    if (result.size() != expected_result.size()){
        NOT_PASSED;
        return;
    }

    for (int i=0; i< result.size(); i++){
        if (result[i].get_id() != expected_result[i].get_id()){
            NOT_PASSED;
            return;
        }
    }

    PASSED;
}

void API_Test::deleteTopology_test(){
    cout << "Test 6/6: deleteTopology test --> ";
    api.deleteTopology("top_test_2");
    if (api.topologies_vector.size() == 0){
        PASSED;
    }else{
        NOT_PASSED;
    }
}

API_Test::API_Test(){

}

API_Test::~API_Test(){

}