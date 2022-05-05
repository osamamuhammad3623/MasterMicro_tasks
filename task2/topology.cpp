#include "topology.h"

void Topology::set_id(string id){
    this->topology_id = id;
}

string Topology::get_id(){
    return this->topology_id;
}

DeviceList Topology::get_devices(){
    return this->devices;
}

void Topology::add_device(Component c){
    this->devices.push_back(c);
}

Topology::Topology(){

}

Topology::~Topology(){

}