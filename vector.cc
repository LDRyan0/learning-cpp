// https://en.cppreference.com/w/cpp/container/vector
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(std::vector<T> v) {
	cout << "{ ";
	for( int i: v) { 
		cout << i << " ";
	}
	cout << "}\n";
}

template <typename T>
void printArray(const T *a, size_t size) { 
	cout << "[ ";
	for(int i = 0; i < size; i++) { 
		cout << a[i] << " ";	
	}
	cout << "]\n";
}


int main() { 
	vector<int> vec;

	for(int i = 0; i < 6; ++i) { 
		vec.push_back(2*i);
	}

	cout << "\nDESCRIPTION" << endl;
	cout << "\tstd::vector<T> is a data structure provided by the C++ standard library which acts\n"
		"\tas a dynamic (resizable) array. The vector has a certain capacity where elements can be\n"
		"\tstored contiguously. Once the limit is reached the capacity is automatically increased by\n"
		"\ta factor of 2 by allocating new memory and copying previous data across. std::vector<T>\n"
		"\tallows for array like access times whilst dealing with the problem of unknown size, with\n"
		"\ta small penalty on reallaction and reassignment once capacity is reached." << endl; 

	cout << "\nvec = ";
	printVector(vec);
	cout << "\nELEMENT ACCESS" << endl;
	cout << "\tvec.front() = " << vec.front() << endl;
	cout << "\t\t- gets the element at the front of the array" << endl;
	
	cout << "\tvec.back() = " << vec.back() << endl;
	cout << "\t\t- gets the element at the back of the array" << endl;
	
	cout << "\tvec.at(3) = " << vec.at(3) << endl;
	cout << "\t\t- gets the elements at the specified index" << endl;
	cout << "\t\t- includes bounds checking, throws std::out_of_range" << endl;
	
	cout << "\tvec[3] = " << vec[3] << endl; 
	cout << "\t\t- can also use [] operator like array access in C" << endl;
	
	cout << "\tvec.data() = ";
	printArray(vec.data(), vec.size());
	cout << "\t\t- returns POINTER to the underlying element stoage" << endl;
	cout << "\t\t- must use vec.size() to work with raw pointer" << endl;
	
	
	cout << "\nCAPACITY" << endl;
	cout << "\tvec.empty() = " << vec.empty() << endl;
	cout << "\t\t returns boolean true(1)/false(0) whether array is empty or not" << endl;
	
	cout << "\tvec.size() = " << vec.size() << endl;
	cout << "\t\t- returns the number of elements (actually present) in the vector" << endl;

	cout << "\tvec.max_size() = " << vec.max_size() << endl;
	cout << "\t\t- returns maximum number of elements due to system/library implementation" << endl;
	
	cout << "\tvec.capacity() = " << vec.capacity() << endl;
	cout << "\t\t- returns the number of elements that can be held in currently allocated storage" << endl;

	cout << "\tvec.reserve(32)\n\t  -> vec.capacity() = " << vec.capacity() << " -> ";
	vec.reserve(32);
	cout << vec.capacity() << endl;
	cout << "\t\t- manually increases the capacity of the vector" << endl;
	cout << "\t\t- does not change size() of vector" << endl;
	cout << "\t\t- function does nothing if reserve amount less than current capacity()" << endl;
	cout << "\t\t- std::length_error if larger than max_size()" << endl;

	cout << "\tvec.shink_to_fit()\n\t  -> vec.capacity() = " << vec.capacity() << " -> ";
	vec.shrink_to_fit();	
	cout << vec.capacity() << endl;
	cout << "\t\t- requests the removal of unused capacity" << endl;
	cout << "\t\t- depends on implementation whether request is fulfilled" << endl;


	cout << "MODIFIERS" << endl;
	
	cout << "\tvec.push_back(12)" << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.push_back(12);
	cout << "\t  -> vec = ";
	printVector(vec);	
	cout << "\t\t- adds an element to the back of the array" << endl;

	cout << "\tvec.pop_back() " << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.pop_back();
	cout << "\t  -> vec = ";
	printVector(vec);
	cout << "\t\t- DOES NOT RETURN back() value" << endl;	

	cout << "\tvec.resize(13)" << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.resize(13);
	cout << "\t  -> vec = ";
	printVector(vec);	
	cout << "\tvec.resize(5)" << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.resize(5);
	cout << "\t  -> vec = ";
	printVector(vec);
	cout << "\t\t- changes the size() of the array" << endl;
	cout << "\t\t- effect of adding 0s if greater than current size" << endl;
	cout << "\t\t- can specify what values to fill instead of 0s if extra" << endl;
	cout << "\t\t- \"chops off\" data if smaller than current size" << endl;


	cout << "\tvec.insert(std::next(vec.begin(), 2), 3)" << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.insert(std::next(vec.begin(), 2), 3);
	cout << "\t  -> vec = ";
	printVector(vec);
	cout << "\t\t- insert before position 2 the value of 3" << endl;
	cout << "\t\t- must use an iterator, quite clunky and would not recommend" << endl;
	cout << "\t\t- complexity linear in distance from (pos) and (end)" << endl;
	cout << "\t\t- must \"shuffle\" all elements down" << endl;

	cout << "\tvec.emplace_back()" << endl;
	cout << "\t\t- same as push_back() but CONSTRUCTS with std::allocator_traits::construct" << endl;
	cout << "\t\t- used for more complex classes/data types that must be constructed" << endl;
	
	cout << "\tvec.emplace()" << endl;
	cout << "\t\t- similar to insert, but CONSTRUCTS" << endl; 
	cout << "\t\t- same complexity as vec.insert(): linear from [pos] to [end]" << endl;
 
	cout << "\tvec.swap()" << endl;
	cout << "\t\t- works on iteration again and is weird, probably stay away" << endl;

	cout << "\tvec.erase(vec.begin() + 2)" << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.erase(vec.begin() + 2);	
	cout << "\t  -> vec = ";
	printVector(vec);
	cout << "\t\t- removes element at (pos)" << endl;
	cout << "\t\t- can also remove multiple elements in range (first, last)" << endl;
	cout << "\t\t- linear complexity from (pos) and (end) as shuffle" << endl;

	cout << "\tvec.clear()" << endl;
	cout << "\t     vec = ";
	printVector(vec);
	vec.clear();
	cout << "\t  -> vec = ";
	printVector(vec);
	cout << "\t\t- clears the contents of the vector" << endl;
	cout << "\t\t- size() goes to 0" << endl;	

}

