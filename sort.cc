#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 20

using namespace std;

template <typename T>
void printArray(const vector<T> &v) {
    cout << "[";
    for(auto x : v) {
        cout << x << " ";    
    }
    cout << "]\n";
}

template <typename T>
void checkSorted(const vector<T> &v) {
    cout << "Checking: ";
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i+1] < v[i]) {
            cout << "\033[31m" << "FAILED\n" << "\033[0m";
            return;
        }         
    }
    cout << "\033[32m" << "PASSED\n" << "\033[0m";
}

template <typename T>
void randomise(vector<T> &v) {
    for(int i = 0; i < v.size(); i++) { 
        v[i] = rand() % N; 
    } 
}


template <typename T>
void bubbleSort(vector<T> &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size() - 1 - i; j++) {
            if(v[j] > v[j+1]) {
                T temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &v) {
    int minIdx;
    for(int i = 0; i < v.size(); i++) {
        minIdx = i;
        for(int j = i; j < v.size(); j++) {
            if(v[j] < v[minIdx]) {
               minIdx = j;
            }
        }
        T temp = v[i];
        v[i] = v[minIdx];
        v[minIdx] = temp;
    }
}

template <typename T>
void insertionSort(vector<T> &v) {
    int i, key, j;
    for(int i = 1; i < v.size(); i++) {
        key = v[i];
        j = i - 1;

        while(v[j] > key && j >= 0) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

template<typename T>
void test(void (*sort)(vector<T>&), vector<T> &arr, string name) {
    cout << name << "\n";
    randomise(arr);
    printArray(arr);
    sort(arr);
    printArray(arr);
    checkSorted(arr);
    cout << "\n";
}

int main() {
    srand(time(NULL));
    vector<int> arr(N);
    
    test(&bubbleSort, arr, "Bubble Sort");
    test(&selectionSort, arr,  "Selection Sort");
    test(&insertionSort, arr, "Insertion Sort");
}
