// pass the data type as a parameter so we don't duplicate code
// templates are expanded at compile time
// "typename" can always be replaced with "class" in declaration

#include <iostream>

// maximum of two variables, can be any data type
template <typename T>
T myMax(T x, T y) {
	return (x > y) ? x : y;
}


// can pass more than one data type as arguments to templates
template <class T, class U> class A { 
	T x;
	U y;
	
	public: 
		A() {std::cout << "Constructor Called" << std::endl;}

};

// can specify default arguments to templates
template <class T, class U = char> class B { 
	T x;
	U y;
	
	public: 
		B() {std::cout << "Constructor Called" << std::endl;}

};

// can pass non-type parameters into templates
template <class T, int max> 
int arrMin(T arr[], int n) { 
	int m = max; 
	for(int i = 0; i < n; i++)
		if (arr[i] < m)
			m = arr[i];
	return m;
};
int main(int argc, char* argv[]) { 
	
	std::cout << myMax<int>(3, 7) << std::endl;
	std::cout << myMax<char>('g', 'e') << std::endl;
	std::cout << myMax<float>(3.2, 3.1) << std::endl;

	A<char, char> a1;
	A<int, double> a2;
	
	B<char> b; // calls B<char, char>

	int arr1[] = {10, 20 , 15, 12};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	char arr2[] = {'g', 'y', 'u', 'c', 'r'};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	
	std::cout << arrMin<int, 10000>(arr1, n1) << std::endl;
	std::cout << arrMin<char, 256>(arr2, n2) << std::endl; // 'c' == 99
	
	return 0;
}
