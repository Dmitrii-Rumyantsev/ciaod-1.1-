#include "cl_5.h"

void cl_5::signal_5(string &msg) {
    cout << "Signal from " << get_absolute_way() << endl;
    msg = msg+ " (class:5)";
}

void cl_5::handler_5(string msg) {
    cout << "Signal to " << get_absolute_way() << " Text : " << msg << endl;
}