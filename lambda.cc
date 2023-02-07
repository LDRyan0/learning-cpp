// LAMBDA EXPRESSIONS
// 		- available in C++11 and above
// 		- allow to write inline anonymous functions
// 		- write code once, invoke function, no duplication
// 		- inline function is very simple, small definition
// 		- fast to execute as inline
// 		- keep all code in same place, don't have to look around file

//		 1  2     3      4        5      6
//		[=] () mutable throw() -> int {		}
// 			
// 		1 : capture clause
//			- lambda functions can capture variables from the surrounding scope
// 			- [&x] is by reference and [x] is by value
// 			- [&] means capture all variables by address in current scope
// 			- [=] means capture all variables by value in current scope
// 			- can reference some by value, some by reference including &/= then negation
// 		2 : parameter list
// 		3 : mutable specification
// 		4 : exception specification
// 		5 : trailing return type
// 			- use this syntax to specify return type
//			- eg: 
// 				auto x1 = [](int i){ return i;} 
// 		6 : lambda body
// 			- can use parameters passed to the lambda function as well as declare new variables

#include <iostream>

int main(int argc, char* argv[]) {
	int x = 0;
	int y = 10;

	// pass references to all variables in encompassing scope of lamdda expression
	auto f1 = [&] () { std::cout << "f1()=" << x << std::endl; };
	
	// pass reference to only x in encompassing scope of lamda expresion
	auto f2 = [&x] () { std::cout << "f2()=" << x << std::endl; };

	// pass value of x to lambda function AT THE TIME OF DEFINITION
	auto f3 = [x] () { std::cout << "f3()=" << x << std::endl; };

	// will not compile as we are only passing y but attempting to use x
	// auto f4 = [y] () { std::cout << x << std::endl; };
	
	// increment x AFTER all the lambda functions have been defined
	++x;

	f1(); // prints 1
	f2(); // prints 1
	f3(); // prints 0
	
	
	return 0;
}
