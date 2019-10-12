#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100, MIN = 1;

int check_value(int mysteryNumber, int guess) {
  if(guess < mysteryNumber) {
    printf("It's more\n");
    return 1;
  } else if(guess > mysteryNumber) {
    printf("It's less\n");
    return 1;
  } else if(guess == mysteryNumber) {
    printf("You win\n");
    return 0;
  } else {
    printf("Unexpected Error.\nExiting\n");
    exit(0);
  }
}

int loop_until_guess(int mysteryNumber, int guess) {
  int nb_of_guesses = 0;
  do {
    printf("What is the number ? ");
    scanf("%d", &guess);
    nb_of_guesses++;
  } while (check_value(mysteryNumber, guess));
  
  return nb_of_guesses;
}

int play_again() {
  char user_input[0];
  int play_again = 1;
  do {
    printf("Would you like to play another game ? (Y/N) ");
    scanf("%d", &user_input[0]);
    printf("%d", user_input[0]);
    if (user_input[0] == 'Y' || user_input[0] == 'y') {
      play_again = 0;
    } else {
      play_again = 1;
    }
  } while (play_again == 0);
}

int main() {
  srand(time(NULL));
  int mysteryNumber = (rand() % (MAX - MIN + 1)) + MIN;
  int guess = 0;

  printf("%d", mysteryNumber);

  int nb_of_try = loop_until_guess(mysteryNumber, guess);
  printf("You found the number in %d try\n", nb_of_try);
  play_again();


  return 0;
}
