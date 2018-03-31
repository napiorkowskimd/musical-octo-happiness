#include "timer.h"

using namespace std;

Timer::Timer(string name) : name(name)
{
    reset();
}

Timer::~Timer()
{
}

void Timer::start()
{
	last_call = chrono::steady_clock::now();
    is_running = true;
}

int Timer::stop()
{
    if(!is_running)
        return 0;
    int elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - last_call).count();
	sample_count++;
	mean += elapsed_time;
	if (elapsed_time > max) {
		max = elapsed_time;
	}
	if (elapsed_time < min) {
		min = elapsed_time;
	}
    total_time += elapsed_time;
    return elapsed_time;
}



void Timer::print_statistics()
{
	if (sample_count == 0) {
		cout << "No times measured on clock " << name << endl;
		return;
	}

	mean /= double(sample_count);
	cout << "results from clock " << name << endl;
    cout << "min, max, mean: " << min << ", " << max << ", " << mean << endl;
}

double Timer::get_mean_time()
{
    if(sample_count == 0)
        return 0.0;
    return mean / double(sample_count);
}

int Timer::get_total_time()
{
    return total_time;
}

int Timer::update()
{
    if(is_running) {
        int elapsed_time = stop();
        start();
        return elapsed_time;
    }else {
       start();
       return 0;
    }
}

void Timer::reset() {
    min = std::numeric_limits<int>::max();
    max = -1;
    mean = 0.0;
    is_running = false;
    total_time = 0;
}
