public class Conditional2 {
    public static void main(String[] args) {
        System.out.println("Enter a number: ");
        Scanner number = new Scanner(System.in);
        if (number % 2 == 0) {
            System.out.println("Number is even"); 
        } else {
            System.out.println("Number is odd");
        }
    }
}
