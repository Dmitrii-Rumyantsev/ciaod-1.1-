#include "cl_2.h"

void cl_2::signal_2(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg+ " (class:2)";
}

void cl_2::handler_2(string msg) {
    cout << "Signal to " << get_absolute_way() << " Text : " << msg << endl;
}