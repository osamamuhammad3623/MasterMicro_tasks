#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include "component.h"

class Resistor: public Component{
public:
    Resistor(string id, float default_v, float min_v, float max_v);
    ~Resistor();
};

#endif /* _RESISTOR_H_ */