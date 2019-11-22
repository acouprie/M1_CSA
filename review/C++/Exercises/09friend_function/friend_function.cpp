#include <iostream>
#include <math.h>

using namespace std;

class Point {
    public:
        Point(int x, int y);
        ~Point();
        int getPositionX();
        int getPositionY();
        void displayCoord();
        friend bool compare(Point a, Point b);
        friend int distance(Point a, Point b);
        friend Point middle(Point a, Point b);
    private:
        int pos_x;
        int pos_y;
};

Point::Point(int x, int y) {
    pos_x = x;
    pos_y = y;
}

Point::~Point(void) {}

int Point::getPositionX( void ) {
    return pos_x;
}

int Point::getPositionY( void ) {
    return pos_y;
}

void Point::displayCoord() {
    cout << "Position X : " << getPositionX();
    cout << " ; Position Y : " << getPositionY() << endl;
}

bool compare(Point a, Point b) {
    bool isSame = false;
    if (a.getPositionX() == b.getPositionX() && a.getPositionY() == b.getPositionY()) {
        isSame = true;
    }
    return isSame;
}

int distance(Point a, Point b) {
    int distance;
    distance = sqrt(a.getPositionX()*a.getPositionX() + b.getPositionY()*b.getPositionY());
    return distance;
}

Point middle(Point a, Point b) {
    int x, y;
    x = (a.getPositionX() + b.getPositionX()) / 2;
    y = (a.getPositionY() + b.getPositionY()) / 2;
    return Point(x, y);
}

int *inputCoordonates(int *coord) {
    int pos_x, pos_y;
    
    cout << "Enter position X : ";
    cin >> pos_x;
    cout << "Enter position Y : ";
    cin >> pos_y;

    coord[0] = pos_x;
    coord[1] = pos_y;

    return coord;
}

int main() {
    int coord[2];
    string boolean;

    cout << "Point 1 : " << endl;
    inputCoordonates(coord);
    Point point1(coord[0], coord[1]);

    cout << endl << "Point 2 : " << endl;
    inputCoordonates(coord);
    Point point2(coord[0], coord[1]);
    cout << endl;

    point1.displayCoord();
    point2.displayCoord();

    cout << endl;
    boolean = compare(point1, point2) ? "True" : "False";
    cout << "Compare : " << boolean << endl;
    cout << "Distance : " << distance(point1, point2) << endl;
    cout << "Middle : ";
    middle(point1, point2).displayCoord();

    return 0;
}
