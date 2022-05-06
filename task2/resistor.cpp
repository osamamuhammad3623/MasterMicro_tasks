#include "resistor.h"
#include "component.h"

Resistor::Resistor(string id, float default_v, float min_v, float max_v){
    this->set_id(id);
    this->set_type("resistor");
    this->set_values(default_v, min_v, max_v);
}

Resistor::~Resistor(){
    
}