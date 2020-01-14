package CompositePattern;

public class IntegerValue extends ArithmeticExpression {
    private int value;

    public IntegerValue(int i) {
        this.value = i;
    }

    public void add(ArithmeticExpression value){}

    public int evaluate() {
        return this.value;
    }
}
