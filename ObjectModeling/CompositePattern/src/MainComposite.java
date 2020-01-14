package CompositePattern;

public class MainComposite {
    // Evaluation of the arithmetic expression 2 + (3 * (5 -2) * 6) /6 + 7
    public static void main(String[] args) {
        ArithmeticExpression complete = new AdditionExpression();
        complete.add(new IntegerValue(2));

        ArithmeticExpression middle = new DivideExpression();
        complete.add(middle);
        complete.add(new IntegerValue(7));

        ArithmeticExpression leftDiv = new MultiplicationExpression();
        middle.add(leftDiv);
        middle.add(new IntegerValue(6));

        ArithmeticExpression subtraction = new SubtractionExpression();
        leftDiv.add(new IntegerValue(3));
        leftDiv.add(new IntegerValue(3));
        //leftDiv.add(subtraction);
        leftDiv.add(new IntegerValue(6));

        subtraction.add(new IntegerValue(5));
        subtraction.add(new IntegerValue(2));
        System.out.println("2 + (3 * (5 -2)) * 6 /6 + 7 = " + complete.evaluate());
    }
}
