#ifndef _API_TEST_
#define _API_TEST_
#include "api.h"
class API_Test{
private: 
    API api;
public:
    void readJSON_test();
    void writeJSON_test();
    void queryTopologies_test();
    void deleteTopology_test();
    void queryDevices_test();
    void queryDevicesWithNetlistNode_test();
    API_Test();
    ~API_Test();
};

#endif /* _API_TEST_ */