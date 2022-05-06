#include "NMOS.h"
#include "component.h"

NMOS::NMOS(string id, float default_v, float min_v, float max_v){
    this->set_id(id);
    this->set_type("nmos");
    this->set_values(default_v, min_v, max_v);
}

NMOS::~NMOS(){
    
}