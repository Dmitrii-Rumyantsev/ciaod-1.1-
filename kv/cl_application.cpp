#include "cl_application.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
cl_application::cl_application(cl_base* head_object) : cl_base(head_object) {

};

void cl_application::build_tree_objects(){
    cl_base* p_head;
    string path,name;
    cin >> name;
    this->set_name(name);
    while(true){
        int i_class;
        cin >> path;
        if (path == "endtree")
            break;

        cin >> name >> i_class;
        p_head = this->find_obj_by_coord(path);
        if(p_head == NULL){
            cout << "Object tree" << endl;
            this->print_tree();
            cout << "The head object " << path << " is not found";
            this->flag = 0;
            return;
        }
        if(i_class == 2)
            cl_base* child = new cl_2(p_head,name);
        else if(i_class == 3){
            cl_base* child = new cl_3(p_head,name);
        }
        else if(i_class == 4){
            cl_base* child = new cl_4(p_head,name);
        }
        else if(i_class == 5){
            cl_base* child = new cl_5(p_head,name);
        }
        else if(i_class == 6){
            cl_base* child = new cl_6(p_head,name);
        }
    }
    while(true){
        string obj_1,obj_2;
        cin >> obj_1;
        if(obj_1 == "end_of_connections")
            break;
        cin >> obj_2;
        cl_base* p_obj_1 = this->find_obj_by_coord(obj_1);
        cl_base* p_obj_2 = this->find_obj_by_coord(obj_2);
        if(p_obj_1 == NULL)
            cout << "Object " << obj_1 << " not found" << endl;
        else if(p_obj_2 == NULL)
            cout << "Object " << obj_2 << " not found" << endl;
        else
            p_obj_1->set_connection(get_signal(p_obj_1),p_obj_2,get_handler(p_obj_2));
    }

}

int cl_application::exec_app() {
    cout << "Object tree" << endl;
    print_tree();
    cl_base *s_now = this;//find от текущего объекта
    string path = "", action = "";
    while (true) {
        string command;
        cin >> command;
        if (command == "END")
            break;
        string first, second;
        cin >> first;
        if (command != "EMIT")
            cin >> second;
        else {
            cin.get();
            getline(cin, second);
        }
        cl_base *p_obj = this->find_obj_by_coord(first);
        if (p_obj == NULL) {
            cout << "Object " << first << " not found" << endl;
            continue;
        } else {
            if (command == "EMIT") {
                if (p_obj->get_ready()) {
                    p_obj->emit_signal(get_signal(p_obj), second);
                }
            } else if (command == "DELETE_CONNECT") {
                cl_base *to_object = this->find_obj_by_coord(second);
                if (to_object != NULL) {
                    to_object->delete_connection(get_signal(p_obj), to_object, get_handler(to_object));
                } else {
                    cout << "Handler object" << second << " not found";
                }
            } else if (command == "SET_CONDITION") {
                p_obj->set_state(stoi(second));
            } else {
                cl_base *to_object = this->find_obj_by_coord(second);
                if (to_object != NULL) {
                    to_object->set_connection(get_signal(p_obj), to_object, get_handler(to_object));
                } else {
                    cout << "Handler object" << second << " not found";
                }
            }
        }
    }
    return 0;
}

void cl_application::signal_1(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg + " (class:1)";
}

void cl_application::handler_1(string msg) {
    cout << "Signal to " << get_absolute_way() << "Text: " << msg << endl;
}

void cl_application::signal_2(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg + " (class:2)";
}

void cl_application::handler_2(string msg) {
    cout << "Signal to " << get_absolute_way() << "Text: " << msg << endl;
}

void cl_application::signal_3(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg + " (class:1)";
}

void cl_application::handler_3(string msg) {
    cout << "Signal to " << get_absolute_way() << "Text: " << msg << endl;
}
    //КВ_4

    /*
    cl_base* p_obj;//Поиск нужен
    cl_base* p_target;//
    p_obj->set_connection(SIGNAL_D(cl_1::signal_f()),p_target,(TYPE_HANDLER)&cl_1::handler_f);*/