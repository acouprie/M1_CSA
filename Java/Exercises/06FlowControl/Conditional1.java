public class Conditional1 {
    public static void main(String[] args) {
        System.out.println("Enter your age: ");
        Scanner age = new Scanner(System.in);
        if (age >= 18) {
            System.out.println("You can vote"); 
        } else {
            System.out.println("You can't vote");
        }
    }
}
