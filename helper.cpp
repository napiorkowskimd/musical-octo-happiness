#include "helper.h"

using namespace std;

Timer::Timer(string name) : name(name)
{
	sample_count = 0;
	min = std::numeric_limits<int>::max();v
	max = -1;
	mean = 0.0;
}

Timer::~Timer()
{
}

void Timer::start()
{
	last_call = chrono::steady_clock::now();
}

void Timer::stop()
{
	int elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - last_call).count();
	sample_count++;
	mean += elapsed_time;
	if (elapsed_time > max) {
		max = elapsed_time;
	}
	if (elapsed_time < min) {
		min = elapsed_time;
	}
	
}

void Timer::print_results()
{
	if (sample_count == 0) {
		cout << "No times measured on clock " << name << endl;
		return;
	}

	mean /= double(sample_count);
	cout << "results from clock " << name << endl;
	cout << "min, max, mean: " << min << ", " << max << ", " << mean << endl;
}
