#include "cl_3.h"

void cl_3::signal_3(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg+ " (class:3) ";
}

void cl_3::handler_3(string msg) {
    cout << "Signal to " << get_absolute_way() << " Text : " << msg << endl;
}