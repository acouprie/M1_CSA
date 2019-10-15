package AdvancedExercises;
import java.util.Scanner;
import java.util.Random;


public class AdvancedExercises {
    public static void guessNumber() {
        Random rand = new Random();
        // Obtain a number between [0 - 100].
        int mysteryNumber = rand.nextInt(101);

        Scanner scan = new Scanner(System.in);
        for (int i = 0; i < 6; i++) {
            System.out.println("Guess the number between 0 and 100:");
            int guess = scan.nextInt();
            if (guess >= 0 && guess <= 100) {
                if (guess < mysteryNumber) {
                    System.out.println("It's more");
                } else if (guess > mysteryNumber) {
                    System.out.println("It's less");
                } else if (guess == mysteryNumber) {
                    System.out.println("You win.");
                } else {
                    System.out.println("Unexpected error\nExiting");
                    System.exit(0);
                }
            } else {
                System.out.println("Number out of range");
            }
        }
        System.out.println("You tried more than 5 times. You loose.");
    }

    public static void hangman() {
        System.out.println("Hanging game !");

        Random rand = new Random();
        Scanner scan = new Scanner(System.in);
        String words[] = {"house", "dog"};
        int life = 8;
        char input;

        int index = rand.nextInt(words.length);
        String mysteryWord = words[index];
        char hiddenWord[] = new char[mysteryWord.length()];

        for (int i = 0; i < mysteryWord.length(); i++) {
            hiddenWord[i] = '_';
            System.out.print(hiddenWord[i] + " ");
        }

        for (int l = 0; l < life; l++) {
            System.out.println("\nEnter a letter (lowercase):");
            input = scan.nextLine().charAt(0);
            for (int i = 0; i < mysteryWord.length(); i++) {
                if (mysteryWord.charAt(i) == input) {
                    hiddenWord[i] = input;
                }
            }

            String convertHiddenWord = new String(hiddenWord);
            System.out.println(convertHiddenWord);
            System.out.println(mysteryWord);
            if(convertHiddenWord == mysteryWord) {
                System.out.println("You win !");
                break;
            }
        }
    }
}
