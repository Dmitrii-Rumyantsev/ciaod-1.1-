
#include "cl_base.h"

cl_base::cl_base(cl_base* head_object, string s_name) {
    this->s_name = s_name;
    this->p_head_object = head_object;


    if (p_head_object != nullptr)
        p_head_object->sub_objects.push_back(this);
}



cl_base::~cl_base() {
    for (int i = 0; i < this->sub_objects.size(); i++) {
        delete sub_objects[i];
    }
}

bool cl_base::set_name(string s_new_name) {
    if (p_head_object != nullptr) {
        for (int i = 0; i < p_head_object->sub_objects.size(); i++) {
            if (p_head_object->sub_objects[i]->get_name() == get_name())
                return false;
        }
    }
    this->s_name = s_new_name;
    return true;
}

string cl_base::get_name() {
    return this->s_name;
}

bool cl_base::can_be_ready(){
    cl_base* root = this;
    while(root->p_head_object){
        if(root->p_head_object->state){
            root = root->p_head_object;
        }
        else{
            return false;
        }
    }
    return true;
}

cl_base* cl_base::get_head_object() {
    return this->p_head_object;
}


cl_base* cl_base::get_sub_object(string s_name) {
    for (int i = 0; i < this->sub_objects.size(); i++) {
        if (sub_objects[i]->get_name() == s_name)
            return this->sub_objects[i];
    }
    return nullptr;
}

int cl_base::count(string s_name)
{
    int counter = 0;

    if (this->get_name() == s_name)
        counter++;

    for (auto p_sub_object : sub_objects)
        counter += p_sub_object->count(s_name);

    return counter;
}

cl_base* cl_base::search_object(string s_name)
{
    if (this->count(s_name) != 1)
        return nullptr;

    if (this->get_name() == s_name)
        return this;

    for (auto p_sub_object : sub_objects)
    {
        cl_base* p_found = p_sub_object->search_object(s_name);
        if (p_found != nullptr)
        {
            return p_found;
        }
    }

    return nullptr;
}


cl_base* cl_base::find_object_from_root(string name) {
    if (true) {
        if (name == s_name)
            return this;
        for (auto &el: sub_objects) {
            if (el->get_name() == s_name)
                return el;
            cl_base* ans = el->find_object_from_root(name);
            if (ans)
                return ans;
        }
    }
    else {
        for (auto &el: sub_objects) {
            if (el->get_name() == name) return el;
        }
    }
    return nullptr;

}

void cl_base::set_state(int state){
    this->state = state;
    if(!state){
        for(auto& el: sub_objects ){
            el->set_state(state);
        }
    }
}

void cl_base::print_tree() {
    static int level = 0;
    for(int i = 0; i < level; i++) {
        cout << "    ";
    }
    cout << s_name << endl;
    level++;
    for(auto sub_object : sub_objects) {
        sub_object->print_tree();
    }
    level--;
}

void cl_base::print_status() {
    static int level = 0;
    for(int i = 0; i < level; i++) {
        cout << "    ";
    }
    if(state) {
        cout << s_name << " is ready" << endl;
    } else {
        cout << s_name << " is not ready" << endl;
    }
    level++;
    for(auto sub_object : sub_objects) {
        sub_object->print_status();
    }
    level--;
}

//Method for overriding the head object for the current one in the hierarchy tree. The method must have one parameter, a pointer to the base class object containing a pointer to the new head object. Overriding the head object for the root object is not allowed. It is not allowed to create a second root object. It is unacceptable when redefining that the new head has two subordinate objects with the same name. The new head object should not belong to objects from the current branch. If redefinition is performed, the method returns the value "true", otherwise "false";

bool cl_base::set_head_object(cl_base* s_now) {//Overriding the head object for the root object is not allowed.
    if (s_now->get_name() == s_name)
        return false;
    // It is not allowed to create a second root object. It is unacceptable when redefining that the new head has two subordinate objects with the same name.
    // The new head object should not belong to objects from the current branch. If redefinition is performed, the method returns the value "true", otherwise "false";
    if (s_now->get_head_object()!= nullptr)
        return false;
    this->p_head_object = s_now;
    return true;
    if (s_now->get_sub_object(s_name)!= nullptr)
        return false;

    if (s_now->get_sub_object(s_now->get_name())!= nullptr)
        return false;

    this->p_head_object = s_now;
    return true;
}

//Method of deleting a subordinate object by name. If the object is not found, the method terminates. One parameter of string type, contains the name of the subordinate object to be deleted;

bool cl_base::delete_sub_object(string s_name) {
    if (this->get_name() == s_name)
        return false;

    for (int i = 0; i < this->sub_objects.size(); i++) {
        if (this->sub_objects[i]->get_name() == s_name) {
            delete this->sub_objects[i];
            this->sub_objects.erase(this->sub_objects.begin() + i);
            return true;
        }
    }
    return false;
}

//A method for getting a pointer to any object in the tree of the hierarchy of objects according to the path (coordinates). Pass the path (coordinate) of the object as a parameter to the method. The coordinate is set in the following form: / - root object; // "object name" - search for an object by a unique name from the root (for uniqueness uniqueness is required within the tree); . - current object; ."object name" - search for an object by a unique name from the current one (for uniqueness, uniqueness is required within the tree branch from the current object); "object name 1"[/"object name 2"] . . . is the relative coordinate from the current object, "object name 1" is the subordinate of the current; /"object name 1"[/"object name 2"] . . . is the absolute coordinate from the root object.

cl_base* cl_base::search_object_from_path(string s_path) {
    cl_base *obj;
    if(s_path[0] == '/') {
        if(s_path.size() == 1) {
            obj = this;
            while(obj->p_head_object){
                obj = obj->p_head_object;
            }
            return obj;
        } else{
            if(s_path[1] == '/') {
                return find_object_from_root(s_path.substr(2));
            } else{
                obj = this;
                while(obj->p_head_object){
                    obj = obj->p_head_object;
                }
                string temp = "";
                for(int i = 1;i <= s_path.size();i++){
                    if(i == s_path.size() || s_path[i] == '/'){
                        obj = obj->find_object_from_root(temp);
                        temp = "";
                    }
                    else{
                        temp += s_path[i];
                    }
                    if(!obj) return obj;
                }
                return obj;
            }
        }
    }
    else{
        if(s_path[0] == '.') {
            return s_now;
        } else{
            obj = s_now;
            string temp = "";
            for(int i = 0;i <= s_path.size();i++){
                if(i == s_path.size() || s_path[i] == '/'){
                    obj = obj->find_object_from_root(temp);
                    temp = "";
                }
                else{
                    temp += s_path[i];
                }
                if(!obj) return obj;
            }
            return obj;
        }
    }
}


