public class LogicalExpressionWith3Variables {
    private TableOfSymbols symbols;

    public Satisfiable constructLogicalExpressionWith3Variables() {
        this.symbols = new TableOfSymbols();
        BooleanVariable a = new BooleanVariable("a", "Phone ring");
        this.symbols.addVariable(a);
        BooleanVariable b = new BooleanVariable("b", "Decision to answer");
        this.symbols.addVariable(b);
        BooleanVariable c = new BooleanVariable("c", "Decision to call");
        this.symbols.addVariable(c);
        BinaryOperand leftConjunction = new And();
        UnaryOperand notA = new Not();
        notA.setOperand(a);
        leftConjunction.setLeftOperand(notA);
        leftConjunction.setRightOperand(c);
        BinaryOperand rightConjunction = new And();
        rightConjunction.setLeftOperand(a);
        rightConjunction.setRightOperand(b);
        BinaryOperand or = new Or();
        or.setLeftOperand(leftConjunction);
        or.setRightOperand(rightConjunction);
        return or;
    }

    public void whenPickUpYourPhone(Satisfiable pickUp) {
        for (int i = 0; i <= Math.pow(2,3) -1; i++) {
            this.symbols. fixTruthValue (i,3);
            if (pickUp.isSatisfiable()) {
                System.out.print("I pick up my phone when: ");
                for (int j = 0; j < 3; j++) {
                    System.out.print(this.symbols.interpretation(j));
                    if (j < 2)
                        System.out.print(" and ");
                }
                System.out.println();
            }
        }
    }

    public void whenNotPickUpYourPhone (Satisfiable pickUp) {
        for (int i = 0; i <= Math.pow(2,3) -1; i++) {
            this.symbols. fixTruthValue (i,3);
            if (!pickUp.isSatisfiable()) {
                System.out.print("I don't pick up my phone when: ");
                for (int j = 0; j < 3; j++) {
                    System.out.print(this.symbols.interpretation(j));
                    if (j < 2)
                        System.out.print(" and ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        LogicalExpressionWith3Variables customer = new LogicalExpressionWith3Variables();
        Satisfiable pickUp = customer.constructLogicalExpressionWith3Variables();
        System.out.print("Evaluation of Boolean expression: ");
        System.out.println(pickUp);
        for (int i = 0; i <= Math.pow(2,3) -1; i++) {
            customer.symbols.fixTruthValue (i,3);
            System.out.println(pickUp.isSatisfiable());
        }
        customer.whenPickUpYourPhone(pickUp);
        customer.whenNotPickUpYourPhone(pickUp);
    }
}
