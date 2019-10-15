package KeyboardInput;
import java.util.Scanner;

public class KeyboardInput {
    public static void scan() {
        System.out.println("Enter your name: ");
        Scanner scan = new Scanner(System.in);
        String name = scan.nextLine();
        System.out.println("Hello " + name);
    }
}
