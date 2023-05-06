//
// Created by dima3 on 04.05.2023.
//

#ifndef UNTITLED9_CL_BASE_H
#define UNTITLED9_CL_BASE_H


#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

class cl_base {
private:
    string s_name;
    int state;
    cl_base* p_head_object;
    vector <cl_base*> sub_objects;
public:
    cl_base* s_now;
    cl_base(cl_base* head_object, string s_name = "Base object");
    ~cl_base();
    bool set_name(string new_name);
    string get_name();
    cl_base* get_head_object();
    cl_base* get_sub_object(string s_name);
    void print_tree();
    int count(string s_name);
    cl_base* search_object(string s_name);
    cl_base* find_object_from_root(string s_name);
    bool can_be_ready();
    void set_state(int state);
    void print_status();

    bool set_head_object(cl_base* now);
    bool delete_sub_object(string find_name);
    cl_base* search_object_from_path(string s_path);

};



#endif //UNTITLED9_CL_BASE_H
