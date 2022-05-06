#ifndef _NMOS_H_
#define _NMOS_H_

#include "component.h"

class NMOS: public Component{
public:
    NMOS(string id, float default_v, float min_v, float max_v);
    ~NMOS();
};

#endif /* _NMOS_H_ */