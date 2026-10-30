// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;

public:
    DynamicArray(int s) {
        size = s;
        arr = new T[size];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T getMax() {
        T max = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    T getMin() {
        T min = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] < min)
                min = arr[i];
        }
        return min;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    int binarySearch(T value) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == value)
                return mid;

            if (arr[mid] < value)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    void replace(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }
};

int main() {
    DynamicArray<int> a(5);

    cout << "Enter 5 numbers: ";
    a.input();

    cout << "Max: " << a.getMax() << endl;
    cout << "Min: " << a.getMin() << endl;

    a.sort();
    cout << "Sorted: ";
    a.print();

    cout << "Index: " << a.binarySearch(3) << endl;

    a.replace(0, 10);
    cout << "After replace: ";
    a.print();

    return 0;
}