#include "api_test.h"
#include "api.h"
#include <iostream>
using namespace std;


int main(){
    cout << "Choose an option:\n" \
        "1. Read a topology from a given JSON file and store it in the memory\n" \
        "2. Write a given topology from the memory to a JSON file\n" \
        "3. Query about which topologies are currently in the memory\n" \
        "4. Delete a given topology from memory\n" \
        "5. Query about which devices are in a given topology\n" \
        "6. Query about which devices are connected to a given netlist node in a given topology\n" \
        "7. Run Unit Tests\n";

    int op;

    API api;
    string name, name2;
    TopologyList list;
    DeviceList dv_list;

    while(1){
        cout << "\nChoose a valid option\n";
        cin >> op;
        while(op<1 && op>7){
            cout << "\nChoose a valid option\n";
            cin >> op;
        }

        switch (op)
        {
        case 1:
            cout << "\nEnter file name (with extension): ";
            cin >> name;
            if (api.readJSON(name)){
                cout << "\n" << name + " is read and topology is loaded into memory successfully.\n";
            }else{
                cout << "Something went wrong\n";
            }
            break;
        
        case 2:
            cout << "\nEnter a valid topology ID: ";
            cin >> name;
            if (api.writeJSON(name)){
                cout << "\n" << name + " is written successfully to output_json_file.json\n";
            }else{
                cout << "Topology not found!\n";
            }
            break;
        
        case 3:
            list = api.queryTopologies();
            if (list.size() == 0){
                cout << "\nNo topologies found.\n";
            }else{
                for (auto topo: list){
                    // print topology info
                    cout << "\nTopology ID: " << topo.get_id() << "\n";
                    cout << "\nComponents in the topology (ID & type):\n";
                    for (auto comp: topo.get_devices()){
                        cout << "Component ID: " << comp.get_id() << "\n";
                        cout << "Component type: " << comp.get_type() << "\n";
                    }
                }
            }
            break;

        case 4:
            cout << "\nEnter a valid topology ID: ";
            cin >> name;
            if (api.deleteTopology(name)){
                cout << "\n" << name + " is deleted successfully\n";
            }else{
                cout << "\nTopology NOT found.\n";
            }
            break;

        case 5:
            cout << "\nEnter a valid topology ID: ";
            cin >> name;
            dv_list = api.queryDevices(name);
            if (dv_list.size() == 0){
                cout << "\nNo Devices found.\n";
            }else{
                cout << "\nComponents found, " << dv_list.size() << ":\n";
                for (auto comp: dv_list){
                    cout << "Component ID: " << comp.get_id() << "\n";
                    cout << "Component type: " << comp.get_type() << "\n";
                    cout << "Default value: " << comp.get_default_value() << "\n";
                    cout << "Minimum value: " << comp.get_min_value() << "\n";
                    cout << "Maximum value: " << comp.get_max_value() << "\n";
                    cout << "\n";
                }
            }
            break;

        case 6:
            cout << "\nEnter a valid topology ID: ";
            cin >> name;
            cout << "\nEnter a netlist node ID: ";
            cin >> name2;
            dv_list = api.queryDevicesWithNetlistNode(name, name2);
            if (dv_list.size() == 0){
                cout << "\nNo connected Devices/Components.\n";
            }else{
                cout << "\nConnected components, " << dv_list.size() << ":\n";
                for (auto comp: dv_list){
                    cout << "Component ID: " << comp.get_id() << "\n";
                    cout << "Component type: " << comp.get_type() << "\n";
                }
            }
            break;

        case 7:
            API_Test tests;
            tests.readJSON_test();
            tests.writeJSON_test();
            tests.queryTopologies_test();
            tests.queryDevices_test();
            tests.queryDevicesWithNetlistNode_test();
            tests.deleteTopology_test();
            break;
        }
    }
    
    return 0;
}