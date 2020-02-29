#include <iostream>

using namespace std;

class Rectangle {
    public:
    int width;
    int heigth;
    Rectangle(int width, int heigth);
    ~Rectangle();
};

Rectangle::Rectangle(int x, int y) {
    width = x;
    heigth = y;
}

Rectangle::~Rectangle(void) {
    cout << "Object is being deleted" << endl;
}

int perimeter(int x, int y) {
    return 2 * (x * y);
}

int surface(int x, int y) {
    return x * y;
}

void displayRectangle(int x, int y) {
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    Rectangle rect1(6, 2);
    int p = perimeter(rect1.width, rect1.heigth);
    int s = surface(rect1.width, rect1.heigth);
    cout << "The perimeter of the rectangle is " << p << " and the surface is " << s << endl;
    displayRectangle(rect1.width, rect1.heigth);
    return 0;
}
