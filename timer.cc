#include <iostream>
#include <chrono>
#include <cmath>

using namespace std::chrono;

int main() { 
	// get start time
	auto start = system_clock::now();
	
	// execute code
	double d = 0;
	long long N = 1000000;
	for(int i=0; i<N; ++i) { 
		d += sqrt(sin(i) * cos(i));
	}	
	
	// get end time and calculate difference
	auto end = system_clock::now();
	auto elapsed = end - start;
	
	std::cout << duration<double, std::milli>(elapsed).count() << "ms" << std::endl;

	return 0;
}
