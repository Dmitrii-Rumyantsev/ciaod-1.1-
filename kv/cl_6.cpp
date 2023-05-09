#include "cl_6.h"

void cl_6::signal_6(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg+ " (class:6)";
}

void cl_6::handler_6(string msg) {
    cout << "Signal to " << get_absolute_way() << " Text : " << msg << endl;
}