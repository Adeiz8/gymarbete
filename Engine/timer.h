#pragma once
#include <chrono>

class timer
{
public:
	timer();
	float mark();
private:
	std::chrono::steady_clock::time_point last;

};

