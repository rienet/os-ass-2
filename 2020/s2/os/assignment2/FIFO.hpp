#include "frame.h"
#include "page.h"
#include <string>
#include <iostream>

using namespace std;

void FIFO(vector<Page> page_table, vector<Frame> frame_table, vector<Frame> memory_traces){
    // go thru the entire memory trace
    for(int time = 0; time<memory_traces.size(); time++){

        //
        int current_page_num = memory_traces[time].page_number;
    }
}