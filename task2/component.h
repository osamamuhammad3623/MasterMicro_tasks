#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include <vector>
using namespace std;


class Component{
private:
    string component_id;
    string component_type;

public:
    Component();
    ~Component();

    /* setters & getters for private attributes */
    void set_type(string type);
    string get_type();

    void set_id(string id);
    string get_id();
};

#endif /* _COMPONENT_H_v */
