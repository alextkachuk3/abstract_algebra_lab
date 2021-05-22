#include "my_timer.h"

namespace mtimer
{
	Timer::Timer(float& time) :time(time)
	{
		start_point = std::chrono::high_resolution_clock::now();
	}
	Timer::~Timer()
	{
		Time end_point = std::chrono::high_resolution_clock::now();
		Duration duration = end_point - start_point;
		time = duration.count();
	}
}