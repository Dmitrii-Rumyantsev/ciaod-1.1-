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
    s_now = this;
    bool flag = true;
    string s_head_name, s_sub_name,path;
    cl_base* p_head = this;
    cl_base* p_sub = nullptr;
    int i_class, i_state;
    cin >> s_head_name;
    this->set_name(s_head_name);
    cl_base* s_now = this;

    do {
        cin >> path;
        if (path == "endtree")
            break;

        cin >> s_sub_name >> i_class;
        p_head = this->find_obj_by_coord(path);
        switch (i_class) {
            case 1:
                p_head = new cl_1(p_head, s_sub_name);
                break;
            case 2:
                p_head = new cl_2(p_head, s_sub_name);
                break;
            case 3:
                p_head = new cl_3(p_head, s_sub_name);
                break;
            case 4:
                p_head = new cl_4(p_head, s_sub_name);
                break;
            case 5:
                p_head = new cl_5(p_head, s_sub_name);
                break;
            case 6:
                p_head = new cl_6(p_head, s_sub_name);
                break;
        }

    }while (true);

}

int cl_application::exec_app() {
    cout << "Object tree" << endl;
    print_tree();
    cl_base* s_now = this;//find от текущего объекта
    bool flag = true;
    string path = "", action = "";
    while (true) {//input FIND object_2/object_4 SET /object_2 FIND //object_7 FIND object_4/object_7 FIND . FIND .object_7 FIND object_4/object_7 MOVE .object_7 SET object_4/object_7 MOVE //object_1 MOVE /object_3. output object_2/object_4 Object name: object_4 Object is set: object_2 //object_7 Object is not found object_4/object_7 Object name: object_7 . Object name: object_2 .object_7 Object name: object_7 object_4/object_7 Object name: object_7 .object_7 Redefining the head object failed Object is set: object_7 //object_1 Dubbing the names of subordinate objects New head object: object_3
        cin >> action;
        if (action == "END") {
            break;
        }
        cin >> path;
        cout << endl;
        if (action =="SET") {//Install – install the current object; For install commands, if the object is found, then output: The object is set to: "object name" otherwise: The object was not found at the specified coordinate: "the desired coordinate of the object"
            if (s_now->get_head_object()){
                cout << "Object is set:    " << s_now->get_name() << endl;
            }
            else{
                cout << "The object was not found at the specified coordinate:    " << this->get_head_object()->get_name() << endl;            }

        }
        if(action =="FIND"){
            if(s_now->find_obj_by_coord(path)){
                cl_base* p_object = s_now->find_obj_by_coord(path);
                cout << path << "     Object name: " << p_object->get_name() << endl;
            }
            else{
                cout << path << " Object is not found" << endl;
            }
        }
    }
    //КВ_4

    /*
    cl_base* p_obj;//Поиск нужен
    cl_base* p_target;//
    p_obj->set_connection(SIGNAL_D(cl_1::signal_f()),p_target,(TYPE_HANDLER)&cl_1::handler_f);*/
}