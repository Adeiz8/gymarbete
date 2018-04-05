#include "timer.h"
using namespace std::chrono;
timer::timer()
{
	last = steady_clock::now();
}

float timer::mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frametime = last - old;
	return frametime.count();
}
