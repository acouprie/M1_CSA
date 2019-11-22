#include <iostream>
using namespace std;

void displayMenu();
int add(int x, int y);
int substract(int x, int y);
int product(int x, int y);
int divide(int x, int y);
int modulo(int x, int y);

int main() {
    displayMenu();
}

void displayMenu() {
    int choice, x, y;
    char redo;
    // display menu
    cout << "MENU" << endl;
    cout << "1. Add" << endl;
    cout << "2. Substract" << endl;
    cout << "3. Product" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Modulus" << endl;
    // get inputs
    cout << "Enter your choice :" << endl;
    cin >> choice;
    cout << "Enter first number :" << endl;
    cin >> x;
    cout << "Enter second number :" << endl;
    cin >> y;
    // perform choice
    switch(choice) {
        case 1 :
            cout << add(x, y) << endl;
            break;
        case 2 :
            cout << substract(x, y) << endl;
            break;
        case 3 :
            cout << product(x, y) << endl;
            break;
        case 4 :
            cout << divide(x, y) << endl;
            break;
        case 5 :
            cout << modulo(x, y) << endl;
            break;
        default :
           cout << endl << "/!\\ Invalid choice" << endl << endl;
           displayMenu();
    }
    // Redo a computation
    cout << "Continue ? Y/N" << endl;
    cin >> redo;
    if (redo == 'Y' || redo == 'y') {
        displayMenu();
    }
}

int add(int x, int y) {
    return x + y;
}

int substract(int x, int y) {
    return x - y;
}

int product(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

int modulo(int x, int y) {
    return x % y;
}

