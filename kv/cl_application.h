//
// Created by dima3 on 04.05.2023.
//

#ifndef UNTITLED9_CL_APPLICATION_H
#define UNTITLED9_CL_APPLICATION_H


#include "cl_base.h"
#include "cl_1.h"

class cl_application : public cl_base {
public:
    cl_application(cl_base* head_object);
    void build_tree_objects();
    int exec_app();

};

#endif //UNTITLED9_CL_APPLICATION_H
