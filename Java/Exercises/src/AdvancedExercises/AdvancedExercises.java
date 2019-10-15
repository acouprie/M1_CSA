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

    public static void drawHangman(int numberOfTries) {
        switch (numberOfTries) {
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }

    public static void hangman() {
        System.out.println("Hanging game !");

        Random rand = new Random();
        Scanner scan = new Scanner(System.in);
        String words[] = {"house", "dog"};

        int index = rand.nextInt(words.length);
        String mysteryWord = words[index];
        for (int i = 0; i < mysteryWord.length(); i++) {
            System.out.print("_ ");
        }

        System.out.println("\nEnter a letter:");
        char input = scan.findInLine(".").charAt(0);

        for (int i = 0; i < mysteryWord.length(); i++) {
            if (mysteryWord.charAt(i) != input) {
                System.out.print("_ ");
            } else {
                System.out.print(mysteryWord.charAt(i) + " ");
            }
        }
    }
}
