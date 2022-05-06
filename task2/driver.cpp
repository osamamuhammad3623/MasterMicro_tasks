#include "api_test.h"
#include <iostream>
using namespace std;

int main(){
    API_Test unit_test;
    
    cout << "Running tests..\n\n";
    unit_test.readJSON_test();
    unit_test.writeJSON_test();
    unit_test.queryTopologies_test();
    unit_test.deleteTopology_test();
    unit_test.queryDevices_test();
    // unit_test.queryDevicesWithNetlistNode_test();

    return 0;
}