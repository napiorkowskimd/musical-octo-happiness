#ifndef _HELPER_H
#define _HELPER_H

#include <chrono>
#include <vector>
#include <iostream>
#include <string>
#include <limits>

class Timer
{
public:
	Timer(std::string);
	~Timer();
	void start();
	void stop();
	void print_results();
private:
	std::chrono::time_point<std::chrono::steady_clock> last_call;
	int sample_count;
	int min, max;
	double mean;
	std::string	name;
};



#endif // !_HELPER_H
