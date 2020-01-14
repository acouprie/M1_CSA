package CompositePattern;

import java.util.ArrayList;

public class MultiplicationExpression extends ArithmeticExpression {
    private ArrayList<ArithmeticExpression> values = new ArrayList();


    public MultiplicationExpression() {}

    public void add(ArithmeticExpression exp) {
        this.values.add(exp);
    }

    public int evaluate() {
        int sol = 1;
        for (int i = 0; i < this.values.size(); i++) {
            sol *= this.values.get(i).evaluate();
        }
        return sol;
    }
}
