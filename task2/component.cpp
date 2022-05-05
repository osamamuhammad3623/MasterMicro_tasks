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

Component::Component(){

}

Component::~Component(){

}