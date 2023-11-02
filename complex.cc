#include <iostream>
#include <cmath>
using namespace std;

class Complex { 
public: 
	double real;
	double imag;

	Complex() : real(0), imag(0) {}
	Complex(double r, double i) : real(r), imag(i) {}

	void input() {	
		cout << "Enter real and imaginary parts respectively: ";
		cin >> real;
		cin >> imag;
	}

	Complex conjugate() { 
		return Complex(real,-imag);
	}

	double mag() { 

		return sqrt(real*real + imag*imag);
	}

	// angle in radians
	double angle() { 
		return atan(imag/real);
	}

	// angle in degrees
	double angleDeg() { 
		return atan(imag/real)*180/M_PI;
	}

	Complex operator + (const Complex &y) { 
		Complex temp;
		temp.real = real + y.real;
		temp.imag = imag + y.imag;		
		return temp;
	}

	Complex operator - (const Complex &y) { 
		Complex temp;
		temp.real = real - y.real;
		temp.imag = imag - y.imag;		
		return temp;
	}
	
	Complex operator * (const Complex &y) { 
		Complex temp;
		temp.real = (real*y.real) - (imag*y.imag);
		temp.imag = (real*y.imag) + (imag*y.real);		
		return temp;
	}

	Complex operator / (const Complex &y) { 
		Complex temp;
		int denom = y.real*y.real + y.imag*y.imag;
		temp.real = (real*y.real + imag*y.imag) / denom;
		temp.imag = (-real*y.imag + imag*y.real) / denom;
		return temp;
	}	
	
	friend ostream& operator << (ostream& os, const Complex& z);
};

ostream& operator << (ostream& os, const Complex& z) {
	if(z.imag>=0) { 
		os << z.real << "+" << z.imag << "i";
	} else {
		os << z.real << z.imag << "i";
	}
	return os;
}

int main() { 
	Complex a(3,4);
	Complex b(1,5);
	
	cout << 
		"The following code demonstrates the construction of a complex\n" 
		"complex number class. Real development should be done with\n"
		"std::complex, however this built for educational purposes to\n"
		"understand C++ classes and operator overloading.\n" 
	<< endl;
	
	cout << "            a = " << a << "\n";
	cout << "            b = " << b << "\n\n";
	
	cout << "       a.real = " << a.real << "\n";
	cout << "       a.imag = " << a.imag << "\n\n";
	
	cout << "a.conjugate() = " << a.conjugate() << "\n";
	cout << "      a.mag() = " << a.mag() << "\n";
	cout << "    a.angle() = " << a.angle() << "\n";
	cout << " a.angleDeg() = " << a.angleDeg() << "\n\n";
	
	cout << "          a+b = " << a + b << "\n";
	cout << "          a-b = " << a - b << "\n";
	cout << "          a*b = " << a * b << "\n";
	cout << "          a/b = " << a / b << "\n\n";

	return 0;
}
