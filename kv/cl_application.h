//
// Created by dima3 on 04.05.2023.
//

#ifndef UNTITLED9_CL_APPLICATION_H
#define UNTITLED9_CL_APPLICATION_H


#include "cl_base.h"
#include "cl_1.h"

class cl_application : public cl_base {
private:
    bool flag = 1;
public:
    cl_application(cl_base* head_object);
    void build_tree_objects();
    int exec_app();
    void signal_1(string&);
    void handler_1(string);
    void signal_2(string&);
    void handler_2(string);
    void signal_3(string&);
    void handler_3(string);

};

#endif //UNTITLED9_CL_APPLICATION_H
