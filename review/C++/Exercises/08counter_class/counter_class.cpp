#include <iostream>

using namespace std;

class Counter {
    public:
        void setCount(int x);
        int getCount(void);
        void incrementCounter(int time);
        void decrementCounter(int time);
        Counter(int count);
        ~Counter();
    private:
        int count;
};

Counter::Counter(int x) {
    count = x;
}

Counter::~Counter(void) {}

void Counter::setCount(int x) {
    if (x < 0) {
        x = 0;
    }
    count = x;
}

int Counter::getCount( void ) {
    return count;
}

void Counter::incrementCounter(int time) {
    int value = getCount();
    for (int i = 0; i < time; i++)
    {
        value++;
    }
    setCount(value);
}

void Counter::decrementCounter(int time) {
    int value = getCount();
    for (int i = 0; i < time; i++)
    {
        value--;
    }
    setCount(value);
}

void displayCounterValue(Counter c, int time) {
    for (int i = 0; i < time; i++)
    {
        cout << "Value of the counter : " << c.getCount() << endl;
    }
}

int main() {
    int init;
    cout << "Initialize the counter :" << endl;
    cin >> init;
    Counter count1(init);
    displayCounterValue(count1, 1);
    count1.incrementCounter(10);
    displayCounterValue(count1, 1);
    count1.decrementCounter(20);
    displayCounterValue(count1, 3);
    return 0;
}
