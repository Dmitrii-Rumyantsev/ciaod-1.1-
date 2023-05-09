//
// Created by dima3 on 04.05.2023.
//

#ifndef UNTITLED9_CL_4_H
#define UNTITLED9_CL_4_H


#include "cl_base.h"
class cl_4 : public cl_base{
public:
    using cl_base::cl_base;
    void signal_4(string& msg);
    void handler_4(string msg);
};


#endif //UNTITLED9_CL_4_H
