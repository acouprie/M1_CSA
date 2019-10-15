package StringCharOperations;
import java.util.Scanner;

public class StringCharOperations {
    public static void removeVowels() {
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        System.out.println("Enter a sentence:");
        Scanner scan = new Scanner(System.in);
        String sentence = scan.nextLine();

        for (int i = 0; i < vowels.length; i++) {
            sentence = sentence.replace(String.valueOf(vowels[i]), "");
        }

        System.out.println("Removing vowels of the sentence:");
        System.out.println(sentence);
    }
}
