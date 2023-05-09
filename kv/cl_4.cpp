#include "cl_4.h"

void cl_4::signal_4(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg+ " (class:4)";
}

void cl_4::handler_4(string msg) {
    cout << "Signal to " << get_absolute_way() << " Text : " << msg << endl;
}