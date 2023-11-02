#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

void func_unsafe(int& counter) {
	for(int i=0; i<10000; ++i) {
		++counter;
	}
}

void func_safe(std::atomic<int>& counter) {
	for(int i=0; i<10000; ++i) {
		++counter;
	}
}

int main() { 
	int counter_unsafe = 0;
	std::atomic<int> counter_safe(0);
	
	std::vector<std::thread> threads_unsafe;
	for(int i=0; i<10; ++i) { 
		threads_unsafe.push_back(std::thread{func_unsafe, std::ref(counter_unsafe)});
	}

	std::vector<std::thread> threads_safe;	
	for(int i=0; i<10; ++i) { 
		threads_safe.push_back(std::thread{func_safe, std::ref(counter_safe)});
	}

	// join threads
	for(auto& t : threads_unsafe) { 
		t.join();
	}

	for(auto& t : threads_safe) { 
		t.join();
	}

	std::cout << "Result (unsafe) = " << counter_unsafe << std::endl;
	std::cout << "  Result (safe) = " << counter_safe << std::endl;

	return 0;
}
