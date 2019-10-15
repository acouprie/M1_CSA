package FlowControl;
import java.util.Scanner;

public class FlowControl {
    public static void conditional1() {
        System.out.println("Enter your age:");
        Scanner scan = new Scanner(System.in);
        int age = scan.nextInt();
        if (age >= 18) {
            System.out.println("You can vote");
        } else {
            System.out.println("You can't vote");
        }
    }

    public static void conditional2() {
        System.out.println("Enter a number: ");
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        if (number % 2 == 0) {
            System.out.println("Number is even");
        } else {
            System.out.println("Number is odd");
        }
    }

    public static void loop1() {
        for (int i = 1; i < 100; i++) {
            if (i % 2 != 0) {
                System.out.println(i);
            }
        }

    }

    public static void loop2() {
        final int MATRIX_SIZE = 3;
        int[][] matrix = new int[MATRIX_SIZE][MATRIX_SIZE];

        // initialize matrix
        int number = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = number;
                number++;
            }
        }

        // print original matrix
        System.out.println("Original matrix");
        for (int[] a : matrix) {
            for (int i : a) {
                System.out.print(i + "\t");
            }
            System.out.println("\n");
        }

        // print transposed matrix
        System.out.println("Transposed matrix");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                System.out.print(matrix[j][i] + "\t");
            }
            System.out.println("\n");
        }
    }
}

