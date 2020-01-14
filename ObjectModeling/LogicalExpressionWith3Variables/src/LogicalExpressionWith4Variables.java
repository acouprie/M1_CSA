public class LogicalExpressionWith4Variables {
    private TableOfSymbols symbols;

    public Satisfiable constructLogicalExpressionWith4Variables() {
        this.symbols = new TableOfSymbols();
        BooleanVariable a = new BooleanVariable("a", "Has enough money");
        this.symbols.addVariable(a);
        BooleanVariable b = new BooleanVariable("b", "Finished homework");
        this.symbols.addVariable(b);
        BooleanVariable c = new BooleanVariable("c", "Public Transport on Strike");
        this.symbols.addVariable(c);
        BooleanVariable d = new BooleanVariable("d", "Family car available");
        this.symbols.addVariable(d);
        BinaryOperand leftConjunction = new And();
        UnaryOperand notC = new Not();
        notC.setOperand(c);
        leftConjunction.setLeftOperand(a);
        leftConjunction.setRightOperand(b);
        BinaryOperand rightConjunction = new Or();
        rightConjunction.setLeftOperand(notC);
        rightConjunction.setRightOperand(d);
        BinaryOperand and = new And();
        and.setLeftOperand(leftConjunction);
        and.setRightOperand(rightConjunction);
        return and;
    }

    public void whenGoOut(Satisfiable goOut) {
        for (int i = 0; i <= Math.pow(2,4) -1; i++) {
            this.symbols. fixTruthValue (i,4);
            if (goOut.isSatisfiable()) {
                System.out.print("I go out when : ");
                for (int j = 0; j < 4; j++) {
                    System.out.print(this.symbols.interpretation(j));
                    if (j < 3)
                        System.out.print(" and ");
                }
                System.out.println();
            }
        }
    }

    public void whenNotGoOut(Satisfiable goOut) {
        for (int i = 0; i <= Math.pow(2,4) -1; i++) {
            this.symbols. fixTruthValue (i,4);
            if (!goOut.isSatisfiable()) {
                System.out.print("I don't go out when : ");
                for (int j = 0; j < 4; j++) {
                    System.out.print(this.symbols.interpretation(j));
                    if (j < 3)
                        System.out.print(" and ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        LogicalExpressionWith4Variables customer = new LogicalExpressionWith4Variables();
        Satisfiable goOut = customer.constructLogicalExpressionWith4Variables();
        System.out.print("Evaluation of Boolean expression: ");
        System.out.println(goOut);
        for (int i = 0; i <= Math.pow(2,4) -1; i++) {
            customer.symbols.fixTruthValue (i,4);
            System.out.println(goOut.isSatisfiable());
        }
        customer.whenGoOut(goOut);
        customer.whenNotGoOut(goOut);
    }
}
