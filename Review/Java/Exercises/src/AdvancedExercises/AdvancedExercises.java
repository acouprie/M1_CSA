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

        for (int l = 0; l < life; life--) {
            System.out.println("\nLife left " + life);
            System.out.println("Enter a letter (lowercase):");
            input = scan.nextLine().charAt(0);
            for (int i = 0; i < mysteryWord.length(); i++) {
                if (mysteryWord.charAt(i) == input) {
                    hiddenWord[i] = input;
                }
            }

            String convertHiddenWord = new String(hiddenWord);
            System.out.println(convertHiddenWord);
            if (convertHiddenWord == mysteryWord) {
                System.out.println("You win !");
                break;
            }
        }
    }

    public static void packageRiceBag() {
        // define the size of bags
        final int BIG_BAGS = 5;
        // not used, keeping as a reference
        // final int LITTLE_BAGS = 1;
        Scanner scan = new Scanner(System.in);

        int numberOfBigBags = 0;
        int numberOfLittleBags = 0;

        // input the kilograms to pack
        System.out.println("Number of kilos of rice (Integer):");
        int kilograms = scan.nextInt();

        // calculate the number of big and little bags required
        if (kilograms / BIG_BAGS >= 1) {
            numberOfBigBags = kilograms / BIG_BAGS;
            numberOfLittleBags = kilograms % BIG_BAGS;
        } else {
            numberOfLittleBags = kilograms;
        }

        // print the result
        System.out.println("You will need " + numberOfBigBags + " big bag(s) and " + numberOfLittleBags + " little bag(s).");
    }

    public static void rockPaperScissor() {
        Scanner scan = new Scanner(System.in);
        final String weapons[] = {"Rock", "Paper", "Scissor"};

        System.out.println("Rock Paper Scissor against the computer!");
        System.out.println("Choose your weapon:\n1. Rock\n2. Paper\n3. Scissor");

        int userWeapon = scan.nextInt() - 1;

        // basic user input validation
        if (userWeapon < 1) {
            userWeapon = 1;
        } else if (userWeapon > 3) {
            userWeapon = 3;
        }

        Random rand = new Random();
        int cpuWeapon = rand.nextInt(3);
        System.out.println(userWeapon);
        System.out.println(cpuWeapon);

        if (userWeapon == cpuWeapon) {
            System.out.println("Draw ! You both choose " + weapons[userWeapon]);
        } else {
            System.out.println("You choose " + weapons[userWeapon]);
            System.out.println("CPU choose " + weapons[cpuWeapon]);
            switch (userWeapon) {
                case 0:
                    if (cpuWeapon == 2) {
                        System.out.println("You win!");
                    } else {
                        System.out.println("You loose.");
                    }
                    break;
                case 1:
                    if (cpuWeapon == 0) {
                        System.out.println("You win!");
                    } else {
                        System.out.println("You loose.");
                    }
                    break;
                case 2:
                    if (cpuWeapon == 1) {
                        System.out.println("You win!");
                    } else {
                        System.out.println("You loose.");
                    }
                    break;
                default:
                    System.out.println("Unknown case");
            }
        }
    }
}
