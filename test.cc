#include <iostream>

int main() {
    for(int i = 0; i < 200; i++) { 
        std::cout << i << ": " << (i & 0b1) << "\n";
    }

    return 0;
}