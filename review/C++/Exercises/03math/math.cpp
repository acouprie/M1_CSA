#include <iostream>
using namespace std;

int main() {
    // initialize
    int x, y, p, s, total;
    cout << "What is x ?" << endl;
    cin >> x;
    cout << "What is y ?" << endl;
    cin >> y;
    // compute
    p = x * y;
    s = x + y;
    total = s * s + p * (s-x) * (p+y);
    // display
    cout << "x * y = " << p << endl;
    cout << "x + y = " << s << endl;
    cout << "s² + p * (s-x) * (p+y) = " << s << endl;

    return 0;
}