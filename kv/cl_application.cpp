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
        p_head = this->search_object_from_path(path);
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
    cl_base* s_now = this;
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
            if (s_now->search_object_from_path(path)){
                s_now = this->search_object_from_path(path);
                cout << "Object is set: " << s_now->get_name() << endl;
            } else {
                cout << "The object was not found at the specified coordinate:" << path << endl;
            }
        }
        if (action =="FIND") {//FIND – finds an object relative to the current one!!! For FIND commands, output: "the desired coordinate of the object" Object name: "the name of the object" If the object is not found, then: "the desired coordinate of the object" Object is not found
            if (this->set_head_object()) {
                if (s_now->search_object_from_path(path)) {
                    cout << path << " Object name: " << s_now->get_name();
                } else {
                    cout << path << "Object is not found" << endl;
                }
            } else {
                cout << path << "Object is not found" << endl;
            }
        }
        if (action == "MOVE") {//MOVE – moves an object relative to the current one!!! For MOVE
            //If the head object is not found, then: "the object's desired coordinate" Head object is not found
            if (this->search_object_from_path(path)) {
                //If the head object could not be redefined, then: "the object's desired coordinate" Redefining the head object failed
                if (this->set_head_object(s_now)) {
                    //If the new main object already has a subordinate with the same name, then output: "the desired coordinate of the object" Duplication of the names of subordinate objects
                    if (s_now->search_object_from_path(path)) {
                        //When trying to reassign the head object to the object on the branch, output: "the coordinate of the new head object" Could not redefine the head object
                        if (this->set_head_object(s_now->search_object_from_path(path))) {
                            cout << " New head object: " << s_now->get_name();
                        } else {
                            cout << path << " Redefining the head object failed" << endl;
                        }
                    } else {
                        cout << path << "Dubbing the names of subordinate objects" << endl;
                    }
                } else {
                    cout << path << "Redefining the head object failed" ;
                }
            } else {
                cout << path << "Head object is not found";
            }

        }
        if(action == "DELETE") {//Method of deleting a subordinate object by name. If the object is not found, the method terminates. One parameter of string type, contains the name of the subordinate object to be deleted;
        if(this->delete_sub_object(path)){//If the subordinate object is deleted, then output: 1 The object "absolute path of the deleted object" has been deleted If the object is not found, then do not output anything.
            cout << "The object " << path << " has been deleted" << endl;
        }
        }
    }
}