#include "component.h"

void Component::set_type(string type){
    this->component_type = type;
}

string Component::get_type(){
    return this->component_type;
}

void Component::set_id(string id){
    this->component_id = id;
}

string Component::get_id(){
    return this->component_id;
}

void Component::set_values(float default_v, float min_v, float max_v){
    this->default_value = default_v;
    this->min_value =  min_v;
    this->max_value = max_v;
}

float Component::get_default_value(){
    return this->default_value;
}

float Component::get_min_value(){
    return this->min_value;
}

float Component::get_max_value(){
    return this->max_value;
}

vector<pair<string,string>> Component::get_netlist(){
    return this->netlist;
}

void Component::set_netlist(vector<pair<string,string>> new_netlist){
    this->netlist = new_netlist;
}

Component::Component(){

}

Component::~Component(){

}