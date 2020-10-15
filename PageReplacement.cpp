/*
created by: Simon Kim, Micahel Eldho
ID: a1749955, a1741804
time:06.08.2020
Contact Email:
Include int main(int argc,char *argv[])
input: argv[1], etc.
output: Screen

input sample:
see assignment sheet

output sample:
see assignment sheet
*/

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

//user stuff idk
#include "frame.h"
using namespace std;

void initial(string input_txt);

int main(int argc,char *argv[]) {
    // initial varaibles
    string input_txt = argv[1];
    initial(input_txt);

    // also initial variables
    int page_size = stoi(argv[2]);
    int frames_in_phys_mem = stoi(argv[3]);
    string algorithm = argv[4];
    int ref_bits;
    int regular_interval;
    int working_set_window;

    if ( algorithm == "ARB" || algorithm == "WSARB-1" || algorithm == "WSARB-2" ){
        ref_bits = stoi(argv[5]);
        regular_interval = stoi(argv[6]);

        if ( algorithm == "WSARB-1" || algorithm == "WSARB-2" ){
            working_set_window = stoi(argv[7]);
        }
    }

    Frame pp;
    pp.name = "pee pee";
    cout << pp.name << endl;

    // stuff below



    //input();          // input data
    //works();          // process data
    //output();         // output result
    return 0;
}

void initial(string input_txt){
  /*   string line;

    ifstream training(input_txt);    
    //reads from input.txt and inputs initial data into vector of customers
    while(getline(training, line)){
        stringstream ss(line);
        Customer tempCustomer;

        ss >> tempCustomer.ID;
        ss >> tempCustomer.arrival_time;
        ss >> tempCustomer.priority;
        ss >> tempCustomer.age;
        ss >> tempCustomer.total_tickets_required;

        // other various variables thatll help later on
        tempCustomer.integerID = stoi( tempCustomer.ID.substr(1) );
        tempCustomer.ticket_quota = -1;
        tempCustomer.runs = tempCustomer.age;
        tempCustomer.ready_flag = false;
        tempCustomer.running = 0;
        tempCustomer.waiting = 0;
        tempCustomer.current_process_ticket = 0;

        customers.push_back(tempCustomer);
    } */
}