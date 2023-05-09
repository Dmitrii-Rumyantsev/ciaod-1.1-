//
// Created by dima3 on 04.05.2023.
//

#ifndef UNTITLED9_CL_2_H
#define UNTITLED9_CL_2_H


#include "cl_base.h"

class cl_2 : public cl_base {
public:
    using cl_base::cl_base;
    void signal_2(string& msg);
    void handler_2(string msg);
};


#endif //UNTITLED9_CL_2_H
