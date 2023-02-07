#include <iostream>
#include <cstdlib> // import c library with "stdlib" with "c" prepended
#include <ctime>

using namespace std;

// can also use #define which is a macro, generally less errors?
const int sides = 6; 
const int rolls = 3;
const int trials = 1000;

// compiler directive, replace wherever this is found with just the code
// no messing around with stack, operating system, etc
inline int rSides() { return (rand()  % sides + 1); }

int main(int argc, char* argv[]) { 
	srand(time(0)); // seed for the rand() function in rsides()

	int size = sides * rolls + 1;
	int arr[size] = { 0 }; // aggregate initisialisation to 0
	int total = 0;

	for(int i = 0; i < trials; i++) { 
		for(int j = 0; j < rolls; j++) {
			total += rSides();
		}
		arr[total]++;
		total = 0;
	}
	for(int i = 0; i < size; i++)  {
		cout << i << " : " << arr[i] << endl;
	}

	return 0;
} 



