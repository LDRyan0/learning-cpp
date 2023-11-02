#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

// the C++11 Chrono library is a collection of classes to work with times
// library consists of following components
// 	- duration
// 	- clock
// 	- time point

// this program gets the current time of day
int main() { 
	// get current time as time_point
	std::chrono::system_clock::time_point tpoint = std::chrono::system_clock::now();
	time_t tt = std::chrono::system_clock::to_time_t(tpoint);

	// convert to local time
	tm* t = localtime(&tt);
	std::cout << std::put_time(t, "%H:%M:%S") << std::endl;
		

	return 0;
}

