// https://en.cppreference.com/w/cpp/container/queuetor
#include <iostream>
#include <queue>

using namespace std;

int main() { 
	queue<int> queue;

	cout << "\nDESCRIPTION" << endl;
	cout << "\tstd::queue<T> is a data structure provided by the C++ standard library which\n"
			"\toperates in a FIFO fashion. Unlike std::deqeue, which is a doubly ended queue,\n"
			"\tstd::queue can only expand and contract from one end. push() adds to the back\n"
			"\tof the queue whilst pop() removes the item from the front of the queue (without\n"
			"\treturning it). There is no means of iterating through a queue, as it is a simple\n"
			"\tFIFO interface. Queues can be implemented with a circular array or a linked list.\n"
			"\tImplementation can vary but usually an array/list hybrid. Use std::array or\n"
			"\tstd::vector unless good reason not to as linked lists are not cache friendly.\n" << endl;

	cout << "CONSTRUCT EXAMPLE QUEUE" << endl;
	for(int i = 0; i < 6; ++i) { 
		queue.push(2*i);
		cout << "\tqueue.push(" << 2*i << ")" << endl;
	}


	cout << "\nELEMENT ACCESS" << endl;
	cout << "\tqueue.front() = " << queue.front() << endl;
	cout << "\t\t- gets the first element of the queue" << endl;
	
	cout << "\tqueue.back() = " << queue.back() << endl;
	cout << "\t\t- gets the last element of the queue " << endl;	
	

	cout << "\nCAPACITY" << endl;
	cout << "\tqueue.empty() = " << queue.empty() << endl;
	cout << "\t\t returns boolean true(1)/false(0) whether queue is empty or not" << endl;
	
	cout << "\tqueue.size() = " << queue.size() << endl;
	cout << "\t\t- returns the number of elements (actually present) in the queue" << endl;

	
	cout << "MODIFIERS" << endl;
	
	cout << "\tqueue.push()" << endl;
	cout << "\t\t- inserts an element at the back of the array" << endl;

	cout << "\tqueue.emplace()" << endl;
	cout << "\t\t- similar to push, but CONSTRUCTS" << endl; 

	cout << "\tqueue.pop() " << endl;
	cout << "\t\t- removes item from front of queue" << endl;
	cout << "\t\t- DOES NOT RETURN front() value" << endl;	
 
	cout << "\tqueue.swap()" << endl;
	cout << "\t\t- works on iterators again and is weird, probably stay away" << endl;

}

