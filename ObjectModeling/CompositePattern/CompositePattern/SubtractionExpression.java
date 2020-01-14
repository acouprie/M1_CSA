package CompositePattern;

import java.util.ArrayList;

public class SubtractionExpression extends ArithmeticExpression {
    private ArrayList<ArithmeticExpression> values = new ArrayList<>();

    public SubtractionExpression() {}

    public void add(ArithmeticExpression exp) {
        this.values.add(exp);
    }

    public int evaluate() {
        int sol = this.values.get(0).evaluate();
        for (int i = 1; i < this.values.size(); i++) {
            sol -= this.values.get(i).evaluate();
        }
        return sol;
    }
}
