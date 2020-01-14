public class Not extends UnaryOperand {
    private BooleanVariable operand;

    @Override
    public void setOperand(BooleanVariable a) {
        this.operand = a;
    }

    @Override
    public boolean isSatisfiable() {
        return !operand.isSatisfiable();
    }

    @Override
    public String toString() {
        return "!" + operand.toString();
    }
}
