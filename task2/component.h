#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include <vector>
using namespace std;


class Component{
private:
    string component_id;
    string component_type;
    vector<pair<string,string>> netlist;

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

    vector<pair<string,string>> get_netlist();
    void set_netlist(vector<pair<string,string>>);
};

#endif /* _COMPONENT_H_v */
