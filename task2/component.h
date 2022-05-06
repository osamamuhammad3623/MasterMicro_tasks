#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


class Component{
private:
    string component_id;
    string component_type;
    json netlist;

    float default_value, min_value, max_value;

public:
    Component();
    ~Component();

    /* setters & getters for private attributes */
    void set_type(string type);
    string get_type();

    void set_id(string id);
    string get_id();

    void set_values(float default_v, float min_v, float max_v);
    float get_default_value();
    float get_min_value();
    float get_max_value();

    json get_netlist();
    void set_netlist(json json_object);
};

#endif /* _COMPONENT_H_v */
