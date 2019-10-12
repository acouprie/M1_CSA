#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <ctype.h>

using namespace std;

void display_menu();
void display_rules();
void init_game(int *shuffled_list);
void display_matrix(int *shuffled_list);
void move(int *shuffled_list);
void exit_program(int input);
int find_number_position(int number, int *shuffled_list);
int win(int *shuffled_list);

// TOKEN will reprensent the blank case
const int TOKEN = 9;
int unshuffled_list[9] = {1, 2, 3, 4, 5, 6, 7, 8, TOKEN};

int main() {
    display_menu();
    return 0;
}

// menu manager
void display_menu() {
    int choice = 0;
    int shuffled_list[9];

    cout << "Press 1 to start" << endl 
    << "-------------" << endl << "1. Start" 
    << endl << "2. Rules" << endl << endl 
    << "Enter a choice:" << endl;
    cin >> choice;
    cout << endl;

    if (choice == 1){
        init_game(shuffled_list);
    } else if (choice == 2 ){
        display_rules();
    } else {
        cout << "Unrecognized answer, please try again" << endl;
    }
}

// shuffle the list
void init_game(int *shuffled_list) {
    srand(time(NULL));
    copy(unshuffled_list, unshuffled_list + 9, shuffled_list);
    random_shuffle(&shuffled_list[0], &shuffled_list[9]);
    display_matrix(shuffled_list);
}

void display_rules() {
    cout << "Read the rules :" << endl 
    << "1. Arrange the nos in ascending order" 
    << endl << "2. Press the no key to move the nos" 
    << endl << "3. X-Exit" << endl << endl;
    display_menu();
}

void display_matrix(int *shuffled_list) {
    cout << endl << "Shuffle:" << endl << endl;
    for (int i = 0; i < 9; i++) {
        if (shuffled_list[i] != TOKEN) {
            cout << shuffled_list[i];
        } else {
            cout << " ";
        }
        if (i % 3 == 2) {
            cout << endl;
        }
    }
    cout << endl;
    win(shuffled_list);
    move(shuffled_list);
}

// find the index of a number
int find_number_position(int number, int *shuffled_list) {
    int index = 0;
    for (int i = 0; i < 9; i++)
    {
        if (number == shuffled_list[i]) {
            index = i;
            break;
        }
    }
    return index;
}

// Check if the list is ordered as the unshuffled list
int win(int *shuffled_list) {
    for (int i = 0; i < 9; i++)
    {
        if (shuffled_list[i] != unshuffled_list[i]) {
            return 1;
        }
    }
    cout << "You win !" << endl;
    exit(EXIT_SUCCESS);
}

// exit when X or x is pressed
void exit_program(int input) {
    if (input == 'x' || input == 'X') {
        exit(EXIT_SUCCESS);
    }
}

void move(int *shuffled_list) {
    int index_input, input_i, index_token;
    string input;
    cout <<  "Enter a digit or X to exit: ";
    cin >> input;
    // check wether it is a char to exit or a int to play
    if(isalpha(input[0])) {
        exit_program(input[0]);
    // if it is a number cast it to input_i
    } else {
        input_i = stoi(input);
    }
    // find position in the array
    index_input = find_number_position(input_i, shuffled_list);
    index_token = find_number_position(TOKEN, shuffled_list);
    // do the exchange if allowed
    if (index_input == index_token + 3 ||
    index_input == index_token - 3 ||
    index_input == index_token + 1 || 
    index_input == index_token - 1) {
        shuffled_list[index_token] = shuffled_list[index_input];
        shuffled_list[index_input] = TOKEN;
    }
    // show the new matrix
    display_matrix(shuffled_list);
}