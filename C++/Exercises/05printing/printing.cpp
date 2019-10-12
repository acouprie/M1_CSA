#include <iostream>

using namespace std;

const int finish = 100;
int first = 0;

void increment(int index);
void decrement(int index);

int main() {
    increment(::first);
    return 0;
}

void increment(int index) {
    cout << index << " ";
    if (index < finish) {
        index++;
        increment(index);
    } else {
        cout << "- ";
        decrement(index);
    }
}

void decrement(int index) {
    cout << index << " ";
    if (index <= finish && index > 0) {
        index--;
        decrement(index);
    } 
}