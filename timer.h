#ifndef _TIMER_H
#define _TIMER_H

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
    int stop();
    int update();
    int get_total_time();
    double get_mean_time();
    void reset();
    void print_statistics();

private:
	std::chrono::time_point<std::chrono::steady_clock> last_call;
	int sample_count;
	int min, max;
	double mean;
    int total_time;
	std::string	name;
    bool is_running;
};



#endif // !_TIMER_H
