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

// user header stuff idk
#include "frame.h"
#include "page.h"
#include "FIFO.hpp"
using namespace std;

vector<Frame> inputConversion(string input_txt, vector<Frame> memory_traces, int page_size);
vector<Page> initialisePageTable(vector<Page> page_table, int page_size);
vector<Frame> initialiseFrameTable(vector<Frame> frame_table, int frames_in_phys_mem);

int main(int argc,char *argv[]){
    // initial varaibles
    string input_txt = argv[1];
    int page_size = stoi(argv[2]);
    int frames_in_phys_mem = stoi(argv[3]);
    string algorithm = argv[4];

    // initial variables for ARB, WSARB 1/2
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

    // initialises necessary data structs
    vector<Page> page_table;
    page_table = initialisePageTable(page_table, page_size);
    vector<Frame> frame_table;
    frame_table = initialiseFrameTable(frame_table, frames_in_phys_mem);

    // see inputConversion() for details
    vector<Frame> memory_traces;
    memory_traces = inputConversion(input_txt, memory_traces, page_size);


    // using if statements to check algorithm to apply rip...
    if( algorithm == "FIFO"){
        FIFO(page_table, frame_table, memory_traces);
    }

    //input();          // input data
    //works();          // process data
    //output();         // output result
    return 0;
}

// reads from input.txt and converts mem traces into a page number
// and corresponding dirty bit. vector of frames is used since it
// can convieniently store these values
vector<Frame> inputConversion(string input_txt, vector<Frame> memory_traces, int page_size){
    string line;

    ifstream training(input_txt);    
    while(getline(training, line)){
        stringstream ss(line);
        Frame temp_frame;

        // initialise the dirty bit depending on trace from input.txt
        char read_or_write;
        ss >> read_or_write;
        if( read_or_write == 'R' ){
            temp_frame.dirty_bit = 0;
        } else if ( read_or_write == 'W' ){
            temp_frame.dirty_bit = 1;
        }

        // basically ignore current line in input.txt if its a comment starting with '#'
        if( read_or_write != '#' ){
            // to convert the address into a page number, we first need to
            // convert it into decimal then divide by the page_size
            int converted_address;
            ss >> hex >> converted_address;
            temp_frame.page_number = converted_address / page_size;
            memory_traces.push_back(temp_frame);
        }
    }

    return memory_traces;
}

// this assumes that the max value of hex is 0000ffff, which is 
// 65535 in decimal form
vector<Page> initialisePageTable(vector<Page> page_table, int page_size){
    int page_table_size = 65536 / page_size;
    for(int i = 0; i<page_table_size; i++){
        Page temp_page;
        temp_page.frame_number = -1;
        temp_page.valid_bit = 0;

        page_table.push_back(temp_page);
    }

    return page_table;
}
vector<Frame> initialiseFrameTable(vector<Frame> frame_table, int frames_in_phys_mem){
    for(int i = 0; i<frames_in_phys_mem; i++){
        Frame temp_frame;
        temp_frame.page_number = -1;
        temp_frame.dirty_bit = 0;

        frame_table.push_back(temp_frame);
    }
    
    return frame_table;
}