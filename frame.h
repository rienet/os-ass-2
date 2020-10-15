#ifndef FRAME_H
#define FRAME_H
#include <string>

class Frame {
public:
	std::string name;
	int dirty_bit;
};

#endif