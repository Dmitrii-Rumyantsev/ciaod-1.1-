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

/*#define SIGNAL_D(signal_f)(TYPE_SIGNAL_D)(&signal_f)
#define HANDLER_D(handle_f)(TYPE_HANDLE_D)(&handler_f)


class cl_base;
typedef void (cl_base::*TYPE_SIGNAL)(string& msg);
typedef void (cl_base::*TYPE_HANDLER)(string msg);

struct o_sh{
    TYPE_SIGNAL p_signal;
    cl_base* p_target;
    TYPE_HANDLER p_handler;

};*/

class cl_base {
private:
    string s_name;
    int state;
    cl_base* p_head_object;
    vector <cl_base*> sub_objects;
    /*vector <o_sh*> connects;*/
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
    cl_base* find_object_from_current(string s_name);
    cl_base* search_object_from_path(string s_path);


    //Факультатив КВ_3
    cl_base* find_obj_by_coord(string s_coord);
    cl_base* get_root();


    //Факультатив КВ_4
/*
    void set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler);
    void delete_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler);
    void emit_signal(TYPE_SIGNAL p_signal, string s_message);*/
};





#endif //UNTITLED9_CL_BASE_H
